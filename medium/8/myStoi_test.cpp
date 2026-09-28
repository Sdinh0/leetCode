#include <climits>
#include <iostream>
#include <string>

#include "myStoi.cpp"

void runTest(const std::string& input, int expected, const std::string& label) {
    Solution sol;
    int actual = sol.myAtoi(input);

    std::cout << label << ": ";
    if (actual == expected) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
        std::cout << "  input    = " << input << std::endl;
        std::cout << "  expected = " << expected << std::endl;
        std::cout << "  actual   = " << actual << std::endl;
        std::exit(1);
    }
}

int main() {
    runTest("42", 42, "basic positive");
    runTest("   -42", -42, "leading whitespace and negative sign");
    runTest("+12", 12, "explicit positive sign");
    runTest("000123", 123, "leading zeros");
    runTest("000", 0, "all zeros");
    runTest("   +000045", 45, "leading spaces and zeros");
    runTest("4193 with words", 4193, "stop at first non-digit");
    runTest("words and 987", 0, "no digits at all");
    runTest("-91283472332", INT_MIN, "below range negative clamp");
    runTest("91283472332", INT_MAX, "above range positive clamp");
    runTest("-+12", 0, "invalid sign sequence");
    runTest("+", 0, "sign with no digits");
    runTest("-", 0, "negative sign with no digits");
    runTest("  -0012a34", -12, "digits before invalid char");
    runTest("  +0000000000000000000001", 1, "large zero prefix positive");
    runTest("  -0000000000000000000001", -1, "large zero prefix negative");
    runTest("  20000000000000000000", INT_MAX, "large positive number");
    runTest("  -2000000000000000000000001", INT_MIN, "large negative number");
    
    std::cout << "All myAtoi tests passed." << std::endl;
    return 0;
}
