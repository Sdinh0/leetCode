#include <iostream>
#include <climits>
#include "reverseInteger.cpp"

void runTest(int x, int expected, int testNumber) {
    Solution solution;
    int result = solution.reverse(x);

    std::cout << "Test " << testNumber << ": ";
    if (result == expected) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\n";
        std::cout << "  x = " << x << "\n";
        std::cout << "  expected = " << expected << "\n";
        std::cout << "  actual = " << result << "\n";
    }
}

int main() {
    runTest(123, 321, 1);
    runTest(-123, -321, 2);
    runTest(120, 21, 3);
    runTest(0, 0, 4);
    runTest(1, 1, 5);
    runTest(-101, -101, 6);
    runTest(10, 1, 7);
    runTest(-10, -1, 8);
    runTest(1534236469, 0, 9);
    runTest(INT_MIN, 0, 10);
    runTest(2147483647, 0, 11);

    return 0;
}
