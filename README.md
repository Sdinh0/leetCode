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

## Running Tests

The test catalog is in `problemList.yaml`. Each problem can list one or more test files under `tests`. Run the configured tests from the repository root with Python 3, PyYAML, and `g++` on your `PATH`:

```sh
python -m pip install PyYAML
python scripts/run-test.py
```

C++ tests include their solution source and define their own `main()`. The runner compiles them as C++17, runs each test, and stores temporary executables outside the repository. Python test files are run with the active Python interpreter.