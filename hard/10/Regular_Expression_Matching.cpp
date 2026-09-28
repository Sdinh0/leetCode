#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // Use two rows: prev for previous row, curr for current row
        vector<bool> prev(n + 1, false);
        vector<bool> curr(n + 1, false);
        
        // Initialize first row
        prev[0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 2];
            }
        }
        
        // Fill remaining rows
        for (int i = 1; i <= m; i++) {
            curr[0] = false;  // Can't match non-empty string with empty pattern
            
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // Two choices:
                    // 1. Match zero: curr[j-2]
                    // 2. Match one or more: prev[j]
                    curr[j] = curr[j - 2];
                    
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        curr[j] = curr[j] || prev[j];
                    }
                } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            
            // Swap for next iteration
            swap(prev, curr);
        }
        
        return prev[n];
    }
};