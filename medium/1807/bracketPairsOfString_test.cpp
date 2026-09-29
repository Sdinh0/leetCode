#include <iostream>
#include <string>
#include <vector>
#include "bracketPairsOfString.cpp"

bool runTest(
    const std::string& s,
    std::vector<std::vector<std::string>> knowledge,
    const std::string& expected,
    int testNumber
) {
    Solution solution;
    std::string result = solution.evaluate(s, knowledge);
    bool passed = result == expected;

    std::cout << "Test " << testNumber << ": ";
    if (passed) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\n";
        std::cout << "  s = \"" << s << "\", expected = \"" << expected
                  << "\", actual = \"" << result << "\"\n";
    }
    return passed;
}

int main() {
    bool allPassed = true;
    allPassed &= runTest("hi(name)", {{"name", "bob"}, {"age", "two"}}, "hibob", 1);
    allPassed &= runTest("(name)is(age)yearsold", {{"name", "bob"}, {"age", "two"}}, "bobistwoyearsold", 2);
    allPassed &= runTest("hi(name)", {{"a", "b"}}, "hi?", 3);
    allPassed &= runTest("(a)(a)(a)aaa", {{"a", "yes"}}, "yesyesyesaaa", 4);
    allPassed &= runTest("(a)(b)", {{"a", "b"}, {"b", "a"}}, "ba", 5);
    allPassed &= runTest("plain text", {}, "plain text", 6);
    allPassed &= runTest("(missing)tail", {}, "?tail", 7);

    return allPassed ? 0 : 1;
}