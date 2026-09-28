#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, currentArea;
        int left = 0, right = height.size()-1;

        while (left < right)
        {
            currentArea = min(height[left], height[right]) * (right - left);

            if (currentArea > maxArea)
            {
                maxArea = currentArea;
            }
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};