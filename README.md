# LeetCode C++ workspace

This workspace is set up for C++ problem solving with IntelliSense and Go to Definition while staying compatible with the LeetCode submission flow.

## Structure

- `leetcode.hpp` contains shared local-only helpers for the editor (standard library includes, `ListNode`, and `TreeNode`).
- Each problem lives in its own directory, for example `121/`.
- `start_problem.sh <problem-id>` creates a problem folder, fetches the problem description, and opens the generated file in the editor.

## Workflow

1. Run `./start_problem.sh <problem-id>`.
2. Implement the solution in the generated `.cpp` file.
3. Run `./test.sh <problem-id>` (or `./test <problem-id>`) to compile and run locally against the per-problem `.tests.dat` file.
4. Submit with `./submit <problem-id>` (or `./submit.sh <problem-id>`) which forwards to the upstream `leetcode exec` command.
5. When submitting to LeetCode, the generated file only relies on the standard LeetCode environment because the local header include is guarded with `__has_include`.

## CLI wrapper

- `leetcode test <problem-id>` and `leetcode exec <problem-id>` are intercepted by the workspace shim at `~/.local/bin/leetcode`, so they route to the repo-local wrappers when you are inside the LeetCode workspace.
- The test wrapper reads the problem’s `.tests.dat` file and uses it to drive a local compile/run harness for the solution file.

## IntelliSense and build support

- `.vscode/c_cpp_properties.json` points IntelliSense at the workspace and the generated CMake compile database.
- `CMakeLists.txt` builds the problem sources as an object library so the workspace can be indexed without requiring a `main` function.
- `.clangd` enables C++23 and includes the workspace root.
