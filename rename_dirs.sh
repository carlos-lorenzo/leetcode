#!/bin/bash

set -euo pipefail
shopt -s nullglob

workspace_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 1. Rename existing numeric directories to match the .cpp filename stem
for dir in "$workspace_dir"/*/; do
    dir_name=$(basename "$dir")
    
    # Only process purely numeric directory names (e.g., 236, 100)
    if [[ "$dir_name" =~ ^[0-9]+$ ]]; then
        cpp_files=("$dir"/*.cpp)
        if ((${#cpp_files[@]})); then
            cpp_filename=$(basename "${cpp_files[0]}")
            # Strip the .cpp extension to get the directory name
            target_name="${cpp_filename%.cpp}"
            
            if [[ "$dir_name" != "$target_name" ]]; then
                echo "Renaming '$dir_name' -> '$target_name'"
                mv "$dir" "$workspace_dir/$target_name"
            fi
        fi
    fi
done

# 2. Update test.sh to find directories matching <id> or <id>.*
test_sh_path="$workspace_dir/test.sh"
if [[ -f "$test_sh_path" ]]; then
    python3 - "$test_sh_path" <<'PY'
import sys
from pathlib import Path

test_sh = Path(sys.argv[1])
content = test_sh.read_text(encoding="utf-8")

# Match old directory lookup logic and insert glob/exact resolution
old_snippet = 'problem_dir="$workspace_dir/$problem_id"'
new_snippet = '''matched_dirs=("$workspace_dir/$problem_id" "$workspace_dir/$problem_id."*)
problem_dir=""
for d in "${matched_dirs[@]}"; do
\tif [[ -d "$d" ]]; then
\t\tproblem_dir="$d"
\t\tbreak
\tfi
done'''

if old_snippet in content:
    updated_content = content.replace(old_snippet, new_snippet)
    test_sh.write_text(updated_content, encoding="utf-8")
    print("Successfully updated test.sh!")
else:
    print("Note: Could not automatically update test.sh. Replace 'problem_dir=\"$workspace_dir/$problem_id\"' manually.")
PY
fi