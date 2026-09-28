#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
        {
            return "";
        }
        int start = 0, len = 1;

        auto findPalindrom = [&](int l, int r)
        {
            while ((l >= 0) && (r < s.size()) && (s[l] == s[r]))
            {
                if (r - l + 1 > len)
                {
                    start = l;
                    len = r - l + 1;
                }
                
                l--;
                r++;
            }
        };

        for (int i = 0; i < s.size(); i++)
        {
            findPalindrom(i, i);
            findPalindrom(i, i+1);
        }
        
        return s.substr(start, len);
    }
};