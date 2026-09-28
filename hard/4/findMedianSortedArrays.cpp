#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0, idx2 = 0;
        int sizeSum = nums1.size() + nums2.size();

        if (sizeSum == 0) return 0.0;   // both empty

        double output;
        int prev = 0, curr = 0;

        for (int i = 0; i <= (sizeSum / 2); i++) {
            prev = curr;

            if (idx1 < nums1.size() &&
                (idx2 >= nums2.size() || nums1[idx1] <= nums2[idx2])) {
                curr = nums1[idx1++];
            } else if (idx2 < nums2.size()) {
                curr = nums2[idx2++];
            } else {
                curr = nums1[idx1++];
            }
        }

        if (sizeSum % 2 == 0) {
            output = (prev + curr) / 2.0;
        } else {
            output = curr;
        }

        return output;
    }
};