#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        bool neg = false;

        auto it = s.begin();
        long long limit = neg ? -(long long)INT_MIN : INT_MAX;

        while (it != s.end() && *it == ' ')
        {
            it++;
        }
        if (it != s.end() && (*it == '+' || *it == '-')) {
            neg = (*it == '-');
            ++it;
        }

        while (it != s.end() && *it >= '0' && *it <= '9')
        {
            int digit = *it - '0';

            if (result > limit / 10 || (result == limit / 10 && digit > limit % 10)) {
                return neg ? INT_MIN : INT_MAX;
            }

            result = result * 10 + digit;
            ++it;
        }
        
        return neg ? -result : result;
    }
};