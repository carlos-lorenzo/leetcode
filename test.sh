#!/bin/bash

set -euo pipefail

if [[ $# -lt 1 ]]; then
	echo "Usage: $0 <problem_id>" >&2
	exit 1
fi

workspace_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
problem_id="$1"
problem_dir="$workspace_dir/$problem_id"
solution_glob="$problem_dir/$problem_id"*.cpp

action="test"

if [[ ! -d "$problem_dir" ]]; then
	echo "Problem directory '$problem_dir' does not exist" >&2
	exit 1
fi

test_data_candidates=(
	"$problem_dir/$problem_id.tests.dat"
	"$problem_dir/$problem_id".*.tests.dat
)

test_data_path=""
for candidate in "${test_data_candidates[@]}"; do
	if [[ -f "$candidate" ]]; then
		test_data_path="$candidate"
		break
	fi
done

if [[ -z "$test_data_path" ]]; then
	echo "No test data found in $problem_dir" >&2
	exit 1
fi

shopt -s nullglob
solution_files=($solution_glob)
shopt -u nullglob

if [[ ${#solution_files[@]} -eq 0 ]]; then
	echo "No solution file found matching $solution_glob" >&2
	exit 1
fi

cd "$problem_dir"

python3 - "$problem_id" "$test_data_path" <<'PY'
from pathlib import Path
import os
import re
import subprocess
import sys
import tempfile
import textwrap

problem_id = sys.argv[1]
input_path = Path(sys.argv[2])
workspace_root = Path.cwd()
solution_path = next(workspace_root.glob(f'{problem_id}*.cpp'))

# Read all lines from the test data file
lines = []
for raw in input_path.read_text(encoding='utf-8').splitlines():
	line = raw.strip()
	if line:
		lines.append(line)

if not lines:
	raise SystemExit(f'No test cases found in {input_path}')

# Extract the Solution class body
source = solution_path.read_text(encoding='utf-8')
class_match = re.search(r'class\s+Solution\s*\{(?P<body>.*?)\};', source, re.S)
if not class_match:
	raise SystemExit(f'Could not find a Solution class in {solution_path}')
body = class_match.group('body')

# Find all possible methods
candidates = []
for match in re.finditer(r'(?P<return>[A-Za-z_][A-Za-z0-9_:<>\*\&\s]*?)\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*\((?P<params>[^)]*)\)\s*\{', body, re.S):
	name = match.group('name')
	if name in {'Solution', '~Solution'}:
		continue
	if match.group('return').strip() in {'public:', 'private:'}:
		continue
	candidates.append(match)

if not candidates:
	raise SystemExit(f'Could not find any methods in {solution_path}')

method_match = None
parsed_params = []
method_name = ""

# Smart method selection
for candidate in candidates:
	raw_params = [param.strip() for param in candidate.group('params').split(',') if param.strip()]
	if not raw_params or not raw_params[0]:
		continue
		
	num_params = len(raw_params)
	current_parsed = []
	valid_parse = True
	
	for param_decl in raw_params:
		p_name_match = re.search(r'([A-Za-z_][A-Za-z0-9_]*)\s*$', param_decl)
		if not p_name_match:
			valid_parse = False
			break
		p_name = p_name_match.group(1)
		
		p_type = param_decl[:param_decl.rfind(p_name)].strip()
		p_type = re.sub(r'^const\s+', '', p_type).strip()
		if p_type.endswith('&'):
			p_type = p_type[:-1].strip()
			
		current_parsed.append({'name': p_name, 'type': p_type})
		
	if not valid_parse:
		continue
		
	if len(lines) % num_params != 0:
		continue
		
	match_heuristic = True
	for line_idx, sample in enumerate(lines):
		p_idx = line_idx % num_params
		p_info = current_parsed[p_idx]
		
		is_array = sample.startswith('[')
		expects_array = 'vector' in p_info['type'].lower()
		
		if expects_array and not is_array:
			match_heuristic = False
			break
		if is_array and not expects_array:
			match_heuristic = False
			break
			
	if match_heuristic:
		method_match = candidate
		parsed_params = current_parsed
		method_name = candidate.group('name')
		break

if not method_match:
	raise SystemExit(f'Could not infer the correct target method matching the .tests.dat file in {solution_path}')

cases = [lines[i:i+len(parsed_params)] for i in range(0, len(lines), len(parsed_params))]

with tempfile.TemporaryDirectory(dir=str(workspace_root)) as tmpdir:
	tmpdir_path = Path(tmpdir)
	harness_path = tmpdir_path / 'main.cpp'

	for idx, case_args in enumerate(cases, start=1):
		
		declarations = []
		call_args = []
		
		for p_idx, arg_val in enumerate(case_args):
			p_info = parsed_params[p_idx]
			
			payload = arg_val
			if payload.startswith('['):
				payload = payload.replace('[', '{').replace(']', '}')
				
			declarations.append(f"{p_info['type']} {p_info['name']} = {payload};")
			call_args.append(p_info['name'])
			
		decls_str = '\n\t\t\t\t'.join(declarations)
		call_args_str = ', '.join(call_args)
		
		# Generate the C++ code with namespace inclusion and vector printer
		harness_path.write_text(textwrap.dedent(f'''
			#include <iostream>
			#include <vector>
			#include <string>
			#include <cstdlib>
			#include <cstdio>
			#include <algorithm>

			using namespace std;

			// Universal vector printer
			template <typename T>
			ostream& operator<<(ostream& os, const vector<T>& v) {{
				os << "[";
				for (size_t i = 0; i < v.size(); ++i) {{
					os << v[i];
					if (i != v.size() - 1) os << ", ";
				}}
				os << "]";
				return os;
			}}

			#include "{solution_path.as_posix()}"

			int main() {{
				Solution solution;
				{decls_str}
				
				auto result = solution.{method_name}({call_args_str});
				
				std::cout << std::endl << "__LEETCODE_RESULT__" << std::endl;
				std::cout << result << std::endl;
				
				return 0;
			}}
		'''), encoding='utf-8')

		binary_path = tmpdir_path / f'case_{idx}'
		subprocess.run([
			'g++', '-std=c++23', '-Wall', '-Wextra', '-pedantic', str(harness_path), '-o', str(binary_path)
		], check=True, cwd=str(workspace_root))
		
		completed = subprocess.run([str(binary_path)], check=False, cwd=str(workspace_root), capture_output=True, text=True)
		if completed.returncode != 0:
			raise SystemExit(completed.stderr or completed.stdout)
		
		stdout_raw = completed.stdout
		parts = stdout_raw.split('\n__LEETCODE_RESULT__\n')
		
		if len(parts) >= 2:
			console_out = parts[0].strip()
			return_val = parts[1].strip()
		else:
			console_out = ""
			return_val = parts[0].replace('__LEETCODE_RESULT__\n', '').strip()
			
		print(f'case {idx}: {return_val}')
		if console_out:
			print('stdout:')
			print(textwrap.indent(console_out, '\t'))
		print()
PY