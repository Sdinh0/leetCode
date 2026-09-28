#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int cycle = 2 * numRows - 2;
        string output = "";
        int sLen = s.size();

        if (numRows == 1 || numRows >= sLen)
            return s;

        for (size_t row = 0; row < numRows; row++)
        {
            for (size_t i = row; i < sLen; i+=cycle)
            {
                output += s[i];

                /* append diagonal, if possible */
                int diagIdx = i + cycle - (2 * row);
                if (row != 0 && row != numRows-1 && diagIdx < sLen)
                {
                    output += s[diagIdx];
                }
                
            }
            
        }
        
        return output;
    }
};