# Repository Guidelines

## Project Structure & Module Organization
Daily challenge archives (`23/04`, `24`, `25`) mirror the YYYY/MM problem drops from LeetCode; each subdirectory holds the source for a single prompt. Topic-driven folders (`dataStruct`, `dynamic planning`, `greed`, `else`, `key`, `we`) group reusable headers (`*.h`), Go entry points, and the occasional Python prototype. Shared helpers such as `tools/map.h` plus scratch runners (`main.c`, `main.go`) live in the repo root. Reproducible experiments sit in `test/`, alongside small driver programs (`test/test1.c`, `test/file.c`) and fixture files (`test/example.txt`). Place new assets beside the closest-matching module and keep helper code centralized in `tools/` so every language target can include it via `#include "tools/map.h"`.

## Build, Test, and Development Commands
- `gcc main.c -I greed -I dataStruct -I tools -std=c17 -Wall -Wextra -O2 -o .build/main.exe`: compile a local driver that stitches headers together; point the include path at whichever topic folder contains the solution under test.
- `clang++ 25\\11\\solution.cpp -I tools -std=c++20 -Wall -Wextra -O2 -o .build/2511.exe && .\\.build\\2511.exe < test\\example.txt`: run C++ implementations that live in the dated folders with sample input.
- `go run main.go`: execute Go stubs or quick playgrounds when validating algorithm ideas.

## Coding Style & Naming Conventions
C/C++ code uses 4-space indents, brace-on-same-line, and camelCase for functions that mirror LeetCode signatures (`largestNumber`, `maxProfit`). Keep headers self-contained; include `<stdlib.h>`, `<string.h>`, etc. directly. Prefer descriptive file names that equal the problem id (`greed/179.h`, `dataStruct/409.h`). Python helpers should follow snake_case and stay under 80 columns to match the existing scripts (`greed/11.py`, `lcs01.py`).

## Testing Guidelines
Driver files inside `test/` document how to wire solutions into simple harnesses. When adding a solution, drop a focused test driver (e.g., `test/179_largestNumber.c`) and feed it sample cases through redirected stdin (`.\\build\\179.exe < test\\example.txt`). Keep assertions explicit so reviewers can trace failing inputs quickly.

## Commit & Pull Request Guidelines
Recent commits use numeric messages (`717`, `251116`) that track the corresponding LeetCode id or date. Continue that convention: `<problem-id>[-optional-note]` keeps history scannable. Pull requests should mention the problem link, describe the approach/complexity, list any new tests, and attach screenshots only when visual assets change. Reference related issues or discussions to make triage easy.
