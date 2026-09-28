
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool pos = x >= 0;
        long long reversedNum;
        string num = to_string(abs((x)));

        if (num.size() == 1)
        {
            return x;
        }
        
        while (num[num.size()-1] == '0')
        {
            num.pop_back();
        }

        std::reverse(num.begin(), num.end());

        reversedNum = pos ? stoll(num) : -stoll(num);

        return (reversedNum > INT_MAX || reversedNum < INT_MIN) ? 0 : reversedNum;
    }
};