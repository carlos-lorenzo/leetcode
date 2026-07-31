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

if [[ ! -d "$problem_dir" ]]; then
    echo "Problem directory '$problem_dir' does not exist" >&2
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
/usr/bin/leetcode exec "$problem_id"
