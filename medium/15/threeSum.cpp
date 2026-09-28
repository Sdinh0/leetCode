#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int midIdx, rightIdx;
        vector<vector<int>> output = {};

        for (size_t leftIdx = 0; leftIdx < nums.size()-2; leftIdx++)
        {
            if (nums[leftIdx] > 0) {
                break;
            }

            if ((leftIdx > 0) && (nums[leftIdx] == nums[leftIdx-1]))
            {
                continue;
            }
            
            midIdx = leftIdx+1;
            rightIdx = nums.size() - 1;

            while (midIdx < rightIdx)
            {
                int sum = nums[leftIdx] + nums[midIdx] + nums[rightIdx];

                if (0 == sum)
                {
                    output.push_back({
                        nums[leftIdx],
                        nums[midIdx],
                        nums[rightIdx]
                    });
                    midIdx++;
                    rightIdx--;

                    while ((midIdx < rightIdx) && (nums[midIdx] == nums[midIdx-1]))
                    {
                        midIdx++;
                    }
                    
                    while ((midIdx < rightIdx) && (nums[rightIdx] == nums[rightIdx+1]))
                    {
                        rightIdx--;
                    }
                    
                }
                else if (sum > 0)
                {
                    rightIdx--;
                }
                else
                {
                    midIdx++;
                }
            }
        }
        
        return output;
    }
};