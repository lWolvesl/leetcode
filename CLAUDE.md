# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview
This is a LeetCode solutions repository organized by date and problem type. The codebase contains solutions in multiple languages including C, C++, Go, and Java. The repository is structured with:
- Date-based directories (e.g., `23/04/`, `25/11/`) containing individual problem solutions
- Data structure implementations in the `dataStruct/` directory (LinkedList, Heap, Tree, etc.)
- Special categories like "dynamic planning" and "else"

## Development Commands

### Building and Running Code
Since this repository contains individual solution files rather than a unified project, compilation and execution is done per file:

**For C/C++ files:**
```bash
# Compile C file
gcc -o solution filename.c

# Compile C++ file
g++ -o solution filename.cpp

# Run the compiled executable
./solution
```

**For Go files:**
```bash
# Run Go file directly
go run filename.go

# Build Go executable
go build filename.go
```

**For Java files:**
```bash
# Compile Java file
javac filename.java

# Run Java program
java filename
```

### Testing Solutions
There are no automated tests in this repository. Each solution should be tested manually by:
1. Compiling/running the solution file directly
2. Verifying output against expected LeetCode test cases
3. Using the data structure helper functions (like `list()`, `len()`, `creatRandomTree()`) for debugging

## Code Architecture

### Data Structures
The repository includes custom implementations of common data structures:
- **LinkedList**: Defined in `dataStruct/LinkedList/lists.h` with `ListNode` struct and utility functions (`createRandomList`, `list`, `array`, `len`)
- **Tree**: Defined in `dataStruct/Tree/Tree.h` with `TreeNode` struct and `creatRandomTree` function
- **Heap**: Basic template implementation in `dataStruct/Heap/Heap.h`
- **Queue**: Priority queue implementation in `dataStruct/Queue/PriorityQueue.c`

### File Organization
- **Date directories**: Solutions organized by year/month (e.g., `25/11/` for November 2025)
- **Language variants**: Some problems have multiple language implementations (e.g., `3005.go`, `3005.cpp`, `3005.java`)
- **Utility headers**: Common tools and data structures in `tools.h` and the `dataStruct/` directory

### Common Patterns
- Solutions often include debug output functions for visualizing data structures
- Random data generation functions are provided for testing (`createRandomList`, `creatRandomTree`)
- Header files use proper include guards and pragma once directives

When working on new solutions, follow the existing patterns and place files in the appropriate date directory based on when the solution was created.