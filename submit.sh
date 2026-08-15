#!/bin/bash

set -euo pipefail

if [[ $# -lt 1 ]]; then
    echo "Usage: $0 <problem_id>" >&2
    exit 1
fi

workspace_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
problem_id="$1"

# Find directory starting with problem_id
shopt -s nullglob
matched_dirs=("$workspace_dir/$problem_id" "$workspace_dir/$problem_id".* "$workspace_dir/$problem_id"-*)
shopt -u nullglob

problem_dir=""
for d in "${matched_dirs[@]}"; do
    if [[ -d "$d" ]]; then
        problem_dir="$d"
        break
    fi
done

if [[ -z "$problem_dir" ]]; then
    echo "Problem directory matching '$problem_id' does not exist in $workspace_dir" >&2
    exit 1
fi

# Locate the .cpp solution file inside the problem directory
shopt -s nullglob
solution_files=("$problem_dir/$problem_id"*.cpp "$problem_dir"/*.cpp)
shopt -u nullglob

if [[ ${#solution_files[@]} -eq 0 ]]; then
    echo "No solution .cpp file found in $problem_dir" >&2
    exit 1
fi

solution_file="${solution_files[0]}"
solution_filename="$(basename "$solution_file")"

# Keep track of temporary symlinks for cleanup
cleanup_items=()
cleanup() {
    for item in "${cleanup_items[@]}"; do
        rm -rf "$item"
    done
}
trap cleanup EXIT

# 1. Temporarily symlink <id> to the renamed folder in workspace root
id_dir_symlink="$workspace_dir/$problem_id"
if [[ ! -e "$id_dir_symlink" ]]; then
    ln -s "$problem_dir" "$id_dir_symlink"
    cleanup_items+=("$id_dir_symlink")
fi

# 2. Temporarily symlink the .cpp file into workspace root
root_cpp_symlink="$workspace_dir/$solution_filename"
if [[ ! -e "$root_cpp_symlink" ]]; then
    ln -s "$solution_file" "$root_cpp_symlink"
    cleanup_items+=("$root_cpp_symlink")
fi

# Run leetcode exec from workspace root
cd "$workspace_dir"
/usr/bin/leetcode exec "$problem_id"