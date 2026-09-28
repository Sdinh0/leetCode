#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int currentDepth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                currentDepth++;
                if (currentDepth > maxDepth)
                {
                    maxDepth = currentDepth;
                }
            }
            else if (c == ')')
            {
                currentDepth--;
            }
        }

        return maxDepth;
    }
};