# Repository Guidelines

## Project Structure & Module Organization
- Algorithms and data structures live under topic folders such as `dataStruct/`, `dynamic planning/`, `greed/`, `else/`, `key/`, and `we/`; each subfolder holds problem-specific source files.
- Shared helpers (e.g., custom containers) sit in `tools/` and `tools.h`; include these with `-Itools` when compiling C/C++.
- Scratch outputs should go to `build/`; `cmake-build-debug/` is IDE-generated and should stay untracked. Tests and small fixtures live in `test/` (see `test/example.txt`).
- Paths with spaces (e.g., `dynamic planning/`) need quoting in shells: `g++ -std=c++17 "dynamic planning/xxx.cpp"`.

## Build, Test, and Development Commands
- C++17 compile (recommended by `.clangd`): `g++ -std=c++17 -O2 -Itools <source>.cpp -o build/<name>`; add `-Wall -Wextra` when iterating.
- C compile: `gcc -O2 -Itools <source>.c -o build/<name>`.
- Go quick run: `go run main.go`.
- Example test build & run: `gcc -Itools test/test1.c -o build/test1 && ./build/test1`.
- Keep binaries inside `build/` and out of version control.

## Coding Style & Naming Conventions
- Use 4-space indentation; prefer braces on new lines consistently across functions and control blocks.
- Favor `snake_case` for C helpers and `CamelCase` types for C++ classes/structs; keep filenames descriptive (`heap_top_k.cpp`, `queue_with_two_stack.c`).
- Rely on standard library containers/algorithms where possible; add brief comments only for non-obvious logic or tricky edge cases.
- Run code through `clang-format` (C/C++) if available; keep Go files formatted via `gofmt`.

## Testing Guidelines
- Add minimal repros under `test/` named after the problem (`test_<id>.c`) and keep fixtures small.
- When adding new logic, provide a tiny driver `main` or test function that exercises edge cases; show expected input/output in comments.
- Prefer deterministic tests; avoid reading/writing outside the repo except for `build/`.

## Commit & Pull Request Guidelines
- Commit messages: short, imperative, and scoped (e.g., `add heap merge helper`, `fix queue pop bug`); avoid bundling unrelated fixes.
- Before opening a PR, summarize the problem solved, approach taken, and key follow-up items; paste the commands you ran (build/test) with outcomes.
- Do not commit generated binaries, IDE folders (`cmake-build-debug/`), or local artifacts.
- Link related issues or references when applicable; include screenshots only if the change affects observable output.***
