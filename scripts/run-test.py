from pathlib import Path
import argparse
import os
import shutil
import subprocess
import sys
import tempfile

import yaml

ROOT_DIR = Path(__file__).resolve().parent.parent


def main():
    parser = argparse.ArgumentParser(description="Run tests for LeetCode problems.")
    parser.add_argument("problem_id", nargs="?", help="run tests for one problem ID")
    args = parser.parse_args()

    with (ROOT_DIR / "problemList.yaml").open(encoding="utf-8") as manifest_file:
        problem_list = yaml.safe_load(manifest_file)

    if not isinstance(problem_list, dict) or not isinstance(problem_list.get("problems"), list):
        print("Invalid problemList.yaml: expected a 'problems' list.", file=sys.stderr)
        return 1

    problems = problem_list["problems"]
    if args.problem_id is not None:
        problems = [
            problem
            for problem in problems
            if isinstance(problem, dict) and str(problem.get("id")) == args.problem_id
        ]
        if not problems:
            print(f"Problem ID {args.problem_id} not found in problemList.yaml.", file=sys.stderr)
            return 1

    compiler = shutil.which("g++")
    test_count = 0
    failures = 0

    with tempfile.TemporaryDirectory(prefix="leetcode-tests-") as temporary_directory:
        build_dir = Path(temporary_directory)

        for problem in problems:
            if not isinstance(problem, dict):
                print("Invalid problem entry: expected a mapping.", file=sys.stderr)
                failures += 1
                continue

            problem_id = problem.get("id", "unknown")
            test_paths = problem.get("tests", [])
            if not isinstance(test_paths, list):
                print(f"Problem {problem_id}: 'tests' must be a list.", file=sys.stderr)
                failures += 1
                continue

            for test_index, test_path in enumerate(test_paths):
                test_count += 1
                if not isinstance(test_path, str):
                    print(f"Problem {problem_id}: test path must be a string.", file=sys.stderr)
                    failures += 1
                    continue

                test_file = ROOT_DIR / test_path
                if not test_file.is_file():
                    print(f"Problem {problem_id}: test file not found: {test_path}", file=sys.stderr)
                    failures += 1
                    continue

                if test_file.suffix == ".cpp":
                    if compiler is None:
                        print("g++ was not found on PATH.", file=sys.stderr)
                        failures += 1
                        continue

                    extension = ".exe" if os.name == "nt" else ""
                    executable = build_dir / f"problem_{problem_id}_{test_index}{extension}"
                    print(f"Building problem {problem_id}: {test_path}", flush=True)
                    compile_result = subprocess.run(
                        [compiler, "-std=c++17", str(test_file), "-o", str(executable)],
                        cwd=ROOT_DIR,
                    )
                    if compile_result.returncode != 0:
                        failures += 1
                        continue

                    command = [str(executable)]
                elif test_file.suffix == ".py":
                    command = [sys.executable, str(test_file)]
                elif test_file.suffix == ".ts":
                    node = shutil.which("node")
                    if node is None:
                        print("Node.js was not found on PATH.", file=sys.stderr)
                        failures += 1
                        continue

                    if not (ROOT_DIR / "node_modules" / "tsx").is_dir():
                        print("tsx was not found. Run 'npm install' from the repository root.", file=sys.stderr)
                        failures += 1
                        continue

                    command = [node, "--import", "tsx", str(test_file)]
                else:
                    print(f"Problem {problem_id}: unsupported test type: {test_path}", file=sys.stderr)
                    failures += 1
                    continue

                print(f"Running problem {problem_id}: {test_path}", flush=True)
                test_result = subprocess.run(command, cwd=ROOT_DIR)
                if test_result.returncode != 0:
                    print(f"Problem {problem_id} failed with exit code {test_result.returncode}.", file=sys.stderr)
                    failures += 1

    if test_count == 0:
        print("No tests were configured in problemList.yaml.", file=sys.stderr)
        return 1

    print(f"\nTest files: {test_count}; failures: {failures}.")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())