#include <iostream>
#include <vector>
#include <algorithm>
#include "twoSum.cpp"

bool equals(const std::vector<int>& a, const std::vector<int>& b) {
    return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin());
}

void runTest(std::vector<int> nums, int target, const std::vector<int>& expected, int testNumber) {
    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);

    std::cout << "Test " << testNumber << ": ";
    if (equals(result, expected)) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\n";
        std::cout << "  nums = [";
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << nums[i];
        }
        std::cout << "], target = " << target << "\n";
        std::cout << "  expected = [";
        for (size_t i = 0; i < expected.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << expected[i];
        }
        std::cout << "]\n";
        std::cout << "  actual   = [";
        for (size_t i = 0; i < result.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << result[i];
        }
        std::cout << "]\n";
    }
}

int main() {
    runTest({2, 7, 11, 15}, 9, {0, 1}, 1);
    runTest({3, 2, 4}, 6, {1, 2}, 2);
    runTest({3, 3}, 6, {0, 1}, 3);
    return 0;
}
