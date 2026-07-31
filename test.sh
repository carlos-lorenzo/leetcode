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

cases = []
for raw in input_path.read_text(encoding='utf-8').splitlines():
    line = raw.strip()
    if line:
        cases.append(line)

if not cases:
    raise SystemExit(f'No test cases found in {input_path}')

source = solution_path.read_text(encoding='utf-8')
class_match = re.search(r'class\s+Solution\s*\{(?P<body>.*?)\};', source, re.S)
if not class_match:
    raise SystemExit(f'Could not find a Solution class in {solution_path}')

body = class_match.group('body')
method_match = None
for match in re.finditer(r'(?P<return>\w(?:\w|::|<.*?>|\s)*)\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*\((?P<params>.*?)\)\s*\{', body, re.S):
    name = match.group('name')
    if name in {'Solution', '~Solution'}:
        continue
    if match.group('return').strip() in {'public:', 'private:'}:
        continue
    method_match = match
    break

if not method_match:
    raise SystemExit(f'Could not infer a callable method from {solution_path}')

method_name = method_match.group('name')
params = [param.strip() for param in method_match.group('params').split(',') if param.strip()]
if len(params) != 1:
    raise SystemExit(f'Only single-parameter methods are supported for local .tests.dat execution; found {len(params)}')

param_decl = params[0]
param_type = re.sub(r'\b(const|unsigned|signed)\b', '', param_decl).strip()
param_type = re.sub(r'\s*&\s*$', '', param_type)
param_type = re.sub(r'\s*\*\s*$', '', param_type)
param_name = re.search(r'([A-Za-z_][A-Za-z0-9_]*)\s*$', param_decl)
if not param_name:
    raise SystemExit(f'Could not infer the parameter name from {param_decl}')
param_name = param_name.group(1)

if 'vector<int>' in param_type or param_type == 'vector<int>':
    parse_fn = lambda text: text
else:
    raise SystemExit(f'Unsupported parameter type for local tests: {param_type}')

with tempfile.TemporaryDirectory(dir=str(workspace_root)) as tmpdir:
    tmpdir_path = Path(tmpdir)
    harness_path = tmpdir_path / 'main.cpp'

    for idx, case in enumerate(cases, start=1):
        payload_literal = case
        if payload_literal.startswith('[') and payload_literal.endswith(']'):
            inner = payload_literal[1:-1].strip()
            payload_literal = f'{{{inner}}}'
        harness_path.write_text(textwrap.dedent(f'''
            #include <iostream>
            #include <vector>
            #include <string>
            #include <cstdlib>
            #include <cstdio>
            #include "{solution_path.as_posix()}"

            int main() {{
                Solution solution;
                std::vector<int> payload = {payload_literal};
                std::cout << solution.{method_name}(payload) << std::endl;
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
        print(f'case {idx}: {completed.stdout.strip()}')
PY
