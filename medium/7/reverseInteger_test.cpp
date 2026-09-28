#include <iostream>
#include <climits>
#include "reverseInteger.cpp"

bool runTest(int x, int expected, int testNumber) {
    Solution solution;
    int result = solution.reverse(x);
    bool passed = result == expected;

    std::cout << "Test " << testNumber << ": ";
    if (passed) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\n";
        std::cout << "  x = " << x << "\n";
        std::cout << "  expected = " << expected << "\n";
        std::cout << "  actual = " << result << "\n";
    }
    return passed;
}

int main() {
    bool allPassed = true;
    allPassed &= runTest(123, 321, 1);
    allPassed &= runTest(-123, -321, 2);
    allPassed &= runTest(120, 21, 3);
    allPassed &= runTest(0, 0, 4);
    allPassed &= runTest(1, 1, 5);
    allPassed &= runTest(-101, -101, 6);
    allPassed &= runTest(10, 1, 7);
    allPassed &= runTest(-10, -1, 8);
    allPassed &= runTest(1534236469, 0, 9);
    allPassed &= runTest(INT_MIN, 0, 10);
    allPassed &= runTest(2147483647, 0, 11);

    return allPassed ? 0 : 1;
}
