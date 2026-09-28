from pathlib import Path
import sys
import yaml

ROOT_DIR = Path(__file__).resolve().parent.parent

def main():
    with (ROOT_DIR / "problemList.yaml").open(encoding="utf-8") as manifest_file:
        problem_list = yaml.safe_load(manifest_file)

    if not isinstance(problem_list, dict) or not isinstance(problem_list.get("problems"), list):
            print("Invalid problemList.yaml: expected a 'problems' list.", file=sys.stderr)
            return 1

    # update the README.md file with the problem list
    readme_path = ROOT_DIR / "README.md"
    if not readme_path.is_file():
        print("README.md not found.", file=sys.stderr)
        return 1

    with readme_path.open(encoding="utf-8") as readme_file:
        readme_content = readme_file.read()

    # find the section between <!-- BEGIN GENERATED PROBLEM LIST --> and <!-- END GENERATED PROBLEM LIST -->
    begin_marker = "<!-- BEGIN GENERATED PROBLEM LIST -->"
    end_marker = "<!-- END GENERATED PROBLEM LIST -->"
    begin_index = readme_content.find(begin_marker)

    end_index = readme_content.find(end_marker)
    if begin_index == -1 or end_index == -1 or begin_index >= end_index:
        print("Could not find the generated problem list section in README.md.", file=sys.stderr)
        return 1

    # generate the new problem list
    new_problem_list = []
    for problem in problem_list["problems"]:
        if not isinstance(problem, dict):
            print("Invalid problem entry: expected a mapping.", file=sys.stderr)
            continue

        problem_id = problem.get("id", "unknown")
        problem_title = problem.get("title", "Unknown Title")
        problem_difficulty = problem.get("difficulty", "Unknown Difficulty")
        problem_has_tests = "tests" in problem and isinstance(problem["tests"], list) and len(problem["tests"]) > 0
        new_problem_list.append(f"- [{problem_id}] {problem_title} ({problem_difficulty}){' - Has Tests' if problem_has_tests else ''}")

    # replace the old problem list with the new one
    content_start = begin_index + len(begin_marker)
    updated_content = (
        readme_content[:content_start]
        + "\n"
        + "\n".join(new_problem_list)
        + "\n"
        + readme_content[end_index:]
    )
    
    with readme_path.open("w", encoding="utf-8") as readme_file:
        readme_file.write(updated_content)

if __name__ == "__main__":
    raise SystemExit(main())