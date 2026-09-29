# LeetCode Solutions

A collection of LeetCode solutions written in C++, Python, and TypeScript. Problems are grouped by difficulty, with each solution stored in a directory named for its LeetCode problem ID.

## Repository Layout

```text
easy/<problem-id>/
medium/<problem-id>/
hard/<problem-id>/
problemList.yaml
```

`problemList.yaml` is the catalog of problems. Each entry records the problem ID, title, difficulty, solution path, and test path when a test is available. Not every solution currently has a test.

## Running Tests

The test catalog is in `problemList.yaml`. Each problem can list one or more test files under `tests`. Run the configured tests from the repository root with Python 3, PyYAML, Node.js 20.6 or later, npm, and `g++` on your `PATH`:

```sh
npm install
python -m pip install PyYAML
python scripts/run-test.py
npm exec -- tsc --noEmit
```

C++ tests include their solution source and define their own `main()`. The runner compiles them as C++17, runs each test, and stores temporary executables outside the repository. Python tests run with the active Python interpreter. TypeScript tests run with Node.js and the locally installed `tsx` loader. Run `npm install` after cloning to install the TypeScript tooling.

<!-- BEGIN GENERATED PROBLEM LIST -->
- [1] Two Sum (Easy) - Has Tests
- [2] Add Two Numbers (Medium) - Has Tests
- [3] Longest Substring Without Repeating Characters (Medium) - Has Tests
- [4] Median of Two Sorted Arrays (Hard)
- [5] Longest Palindromic Substring (Medium)
- [6] Zigzag Conversion (Medium)
- [7] Reverse Integer (Medium) - Has Tests
- [8] String to Integer (atoi) (Medium) - Has Tests
- [9] Palindrome Number (Easy)
- [10] Regular Expression Matching (Hard) - Has Tests
- [11] Container With Most Water (Medium) - Has Tests
- [12] Integer to Roman (Medium)
- [13] Roman to Integer (Easy)
- [14] Longest Common Prefix (Easy)
- [15] 3Sum (Medium)
- [16] 3Sum Closest (Medium)
- [17] Letter Combinations of a Phone Number (Medium)
- [18] 4Sum (Medium)
- [3871] Count Commas in Range II (Medium)
- [1563] Stone Game V (Hard) - Has Tests
- [352] Data Stream as Disjoint Intervals (Hard)
- [1032] Stream of Characters (Hard)
- [703] Kth Largest Element in a Stream (Easy)
- [460] LFU Cache (Hard)
- [146] LRU Cache (Medium)
- [3014] Minimum Number of Pushes to Type Word I (Easy)
- [1614] Maximum Nesting Depth of the Parentheses (Easy)
- [1807] Evaluate the Bracket Pairs of a String (Medium) - Has Tests
- [20] Valid Parentheses (Easy) - Has Tests
<!-- END GENERATED PROBLEM LIST -->