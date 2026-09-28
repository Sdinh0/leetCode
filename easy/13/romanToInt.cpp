#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        auto value = [&](char symbol) {
            switch (symbol) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
            }
            return 0;
        };
        int result = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            int currentValue = value(s[i]);
            int nextValue = i + 1 < s.size() ? value(s[i + 1]) : 0;

            result += currentValue < nextValue ? -currentValue : currentValue;
        }
        
        return result;
    }
};