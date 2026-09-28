#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = (int)stoneValue.size();
        if (n <= 1) return 0;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // interval length
        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                long long best = 0;

                for (int k = l; k < r; ++k) {
                    long long leftSum = prefix[k + 1] - prefix[l];
                    long long rightSum = prefix[r + 1] - prefix[k + 1];

                    long long candidate = 0;

                    if (leftSum < rightSum) {
                        candidate = leftSum + dp[l][k];
                    } else if (rightSum < leftSum) {
                        candidate = rightSum + dp[k + 1][r];
                    } else {
                        candidate = leftSum + max(dp[l][k], dp[k + 1][r]);
                    }

                    best = max(best, candidate);
                }

                dp[l][r] = (int)best;
            }
        }

        return dp[0][n - 1];
    }
};