#include <iostream>
#include <vector>
#include <cassert>
#include "maxWaterContainer.cpp"
using namespace std;

int main() {
    Solution sol;
    int passed = 0;
    int failed = 0;

    // Test case 1: Example from problem - [1,8,6,2,5,4,8,3,7]
    // Expected: 49 (between index 1 and 8: min(8,7) * (8-1) = 7 * 7 = 49)
    {
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result = sol.maxArea(height);
        int expected = 49;
        if (result == expected) {
            cout << "Test 1 PASSED: [1,8,6,2,5,4,8,3,7] => " << result << endl;
            passed++;
        } else {
            cout << "Test 1 FAILED: [1,8,6,2,5,4,8,3,7] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 2: Example from problem - [1,1]
    // Expected: 1 (min(1,1) * (1-0) = 1 * 1 = 1)
    {
        vector<int> height = {1, 1};
        int result = sol.maxArea(height);
        int expected = 1;
        if (result == expected) {
            cout << "Test 2 PASSED: [1,1] => " << result << endl;
            passed++;
        } else {
            cout << "Test 2 FAILED: [1,1] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 3: Increasing heights - [1,2,3,4,5]
    // Expected: 8 (between index 0 and 4: min(1,5) * (4-0) = 1 * 4 = 4) or other combinations
    {
        vector<int> height = {1, 2, 3, 4, 5};
        int result = sol.maxArea(height);
        int expected = 8; // between index 1 and 4: min(2,5) * (4-1) = 2 * 3 = 6, or index 2,4: min(3,5)*2=6, or index 3,4: min(4,5)*1=4, or index 2,3: min(3,4)*1=3
        // Actually: max is min(2,5) * 3 = 6 or min(3,5) * 2 = 6 or min(4,5) * 1 = 4, etc.
        // Let me recalculate: index 0,4: min(1,5)*4=4, 1,4: min(2,5)*3=6, 2,4: min(3,5)*2=6, 3,4: min(4,5)*1=4
        // So expected should be 6
        expected = 6;
        if (result == expected) {
            cout << "Test 3 PASSED: [1,2,3,4,5] => " << result << endl;
            passed++;
        } else {
            cout << "Test 3 FAILED: [1,2,3,4,5] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 4: Two tall bars - [8, 7]
    // Expected: 7 (min(8,7) * (1-0) = 7 * 1 = 7)
    {
        vector<int> height = {8, 7};
        int result = sol.maxArea(height);
        int expected = 7;
        if (result == expected) {
            cout << "Test 4 PASSED: [8,7] => " << result << endl;
            passed++;
        } else {
            cout << "Test 4 FAILED: [8,7] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 5: Decreasing heights - [5,4,3,2,1]
    // Expected: max area with minimum distance at the start
    {
        vector<int> height = {5, 4, 3, 2, 1};
        int result = sol.maxArea(height);
        int expected = 12; // 0,1: min(5,4)*1=4, 0,2: min(5,3)*2=6, 0,3: min(5,2)*3=6, 0,4: min(5,1)*4=4, etc.
        // Actually all starting from 0: 0,1=4, 0,2=6, 0,3=6, 0,4=4. Max is 6
        expected = 6;
        if (result == expected) {
            cout << "Test 5 PASSED: [5,4,3,2,1] => " << result << endl;
            passed++;
        } else {
            cout << "Test 5 FAILED: [5,4,3,2,1] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 6: Large values at ends - [2,3,4,5,18,17,6]
    // Expected: area with indices 4,5: min(18,17)*1=17
    {
        vector<int> height = {2, 3, 4, 5, 18, 17, 6};
        int result = sol.maxArea(height);
        int expected = 17; // indices 4,5: min(18,17) * (5-4) = 17 * 1 = 17
        if (result == expected) {
            cout << "Test 6 PASSED: [2,3,4,5,18,17,6] => " << result << endl;
            passed++;
        } else {
            cout << "Test 6 FAILED: [2,3,4,5,18,17,6] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 7: All same height - [3,3,3,3]
    // Expected: min(3,3) * (3-0) = 3 * 3 = 9 or min(3,3) * (2-0) = 6, etc.
    {
        vector<int> height = {3, 3, 3, 3};
        int result = sol.maxArea(height);
        int expected = 9; // indices 0,3: min(3,3)*(3-0)=9
        if (result == expected) {
            cout << "Test 7 PASSED: [3,3,3,3] => " << result << endl;
            passed++;
        } else {
            cout << "Test 7 FAILED: [3,3,3,3] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 8: Zero and large value - [0, 1000]
    // Expected: 0 (min(0, 1000) * (1-0) = 0)
    {
        vector<int> height = {0, 1000};
        int result = sol.maxArea(height);
        int expected = 0;
        if (result == expected) {
            cout << "Test 8 PASSED: [0,1000] => " << result << endl;
            passed++;
        } else {
            cout << "Test 8 FAILED: [0,1000] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 9: Small array with one tall bar - [1, 100, 1]
    // Expected: 100 (indices 0,2: min(1,1)*(2-0)=2, or 1,2: min(100,1)*1=1, or 0,1: min(1,100)*1=1) => max is 2
    {
        vector<int> height = {1, 100, 1};
        int result = sol.maxArea(height);
        int expected = 2; // indices 0,2: min(1,1)*(2-0)=2
        if (result == expected) {
            cout << "Test 9 PASSED: [1,100,1] => " << result << endl;
            passed++;
        } else {
            cout << "Test 9 FAILED: [1,100,1] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Test case 10: Wide container - [1,1,1,1,1,1,1,1,1,1,1]
    // Expected: 10 (indices 0,10: min(1,1)*(10-0)=10)
    {
        vector<int> height = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        int result = sol.maxArea(height);
        int expected = 10; // indices 0,10: min(1,1)*(10-0)=10
        if (result == expected) {
            cout << "Test 10 PASSED: [1,1,1,1,1,1,1,1,1,1,1] => " << result << endl;
            passed++;
        } else {
            cout << "Test 10 FAILED: [1,1,1,1,1,1,1,1,1,1,1] => Got " << result << ", Expected " << expected << endl;
            failed++;
        }
    }

    // Summary
    cout << "\n========== TEST SUMMARY ==========" << endl;
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;
    cout << "Total:  " << (passed + failed) << endl;

    return (failed == 0) ? 0 : 1;
}
