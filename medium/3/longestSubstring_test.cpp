#include <string>
#include <iostream>
#include "longestSubstring.cpp"

void substringTest(const std::string input, const int result, int testNumber)
{
    Solution solution;
    if (result == solution.lengthOfLongestSubstring(input))
    {
        std::cout << "PASSED" << std::endl; 
    }
    else
    {
        std::cout << "FAILED: " << testNumber << std::endl;
    }
}

int main()
{
    substringTest("abcabcbb", 3, 0);
    substringTest("bbbbb", 1, 1);
    substringTest("pwwkew", 3, 2);
    return 0;
}