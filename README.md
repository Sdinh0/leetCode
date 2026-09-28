# LeetCode Solutions

A collection of LeetCode solutions written in C++ and Python. Problems are grouped by difficulty, with each solution stored in a directory named for its LeetCode problem ID.

## Repository Layout

```text
easy/<problem-id>/
medium/<problem-id>/
hard/<problem-id>/
problemList.yaml
```

`problemList.yaml` is the catalog of problems. Each entry records the problem ID, title, difficulty, solution path, and test path when a test is available. Not every solution currently has a test.

## Running a C++ Test

Tests are standalone C++ programs; they include their solution source and define their own `main()`. With `g++` available on your `PATH`, build and run a test from the repository root, for example:

```sh
g++ -std=c++17 medium/3/longestSubstring_test.cpp -o medium/3/longestSubstring_test
./medium/3/longestSubstring_test
```

On Windows, run the generated executable as `medium\3\longestSubstring_test.exe`. The VS Code build task also has a dedicated target for this example test.

Python solutions can be run with Python 3; there is currently no shared test runner or project-wide dependency configuration.