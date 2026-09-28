#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        if (4 > n)
        {
            return result;
        }
        
        sort(nums.begin(), nums.end()) ;

        for (int first = 0; first < n-3; first++)
        {
            if ((0 < first) && (nums[first] == nums[first-1]))
            {
                continue;
            }

            for (int second = first + 1; second < n-2; second++)
            {
                if ((first + 1 < second) && (nums[second] == nums[second-1]))
                {
                    continue;
                }

                int third = second + 1;
                int fourth = n - 1;

                while (third < fourth)
                {
                    long long sum = (long long)nums[first] + nums[second] + nums[third] + nums[fourth];

                    if (sum == target)
                    {
                        result.push_back({nums[first], nums[second], nums[third], nums[fourth]});

                        while ((third < fourth) && (nums[third] == nums[third+1]))
                        {
                            third++;
                        }

                        while ((third < fourth) && (nums[fourth] == nums[fourth-1]))
                        {
                            fourth--;
                        }

                        third++;
                        fourth--;
                    }
                    else if (sum < target)
                    {
                        third++;
                    }
                    else
                    {
                        fourth--;
                    }
                }
            }
            
        }

        return result;
        
    }
};