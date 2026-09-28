#include <string>
#include <iostream>
#include "longestSubstring.cpp"

bool substringTest(const std::string input, const int result, int testNumber)
{
    Solution solution;
    bool passed = result == solution.lengthOfLongestSubstring(input);
    if (passed)
    {
        std::cout << "PASSED" << std::endl; 
    }
    else
    {
        std::cout << "FAILED: " << testNumber << std::endl;
    }
    return passed;
}

int main()
{
    bool allPassed = true;
    allPassed &= substringTest("abcabcbb", 3, 0);
    allPassed &= substringTest("bbbbb", 1, 1);
    allPassed &= substringTest("pwwkew", 3, 2);
    return allPassed ? 0 : 1;
}