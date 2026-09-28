#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        {
            return "";
        }
        
        string prefix = strs[0];
        
        for (size_t strIdx = 1; strIdx < strs.size(); strIdx++)
        {
            size_t i = 0;

            while (i < strs[strIdx].size() &&
                   i < prefix.size() &&
                   prefix[i] == strs[strIdx][i])
            {
                ++i;
            }
            
            prefix.resize(i);
        }
        
        return prefix;
    }
};