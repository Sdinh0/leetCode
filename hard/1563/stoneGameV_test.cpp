#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#include "stoneGameV.cpp"

int main() {
    Solution sol;

    struct TestCase {
        vector<int> stones;
        int expected;
    };

    vector<TestCase> tests = {
        {{6, 2, 3, 4, 5, 5}, 18},
        {{7, 7, 7, 7, 7, 7, 7}, 28},
        {{4}, 0},
        {{1, 1}, 1},
        {{1, 1, 1}, 1},
        {{5, 5, 5}, 5},
        {{1, 2, 3}, 4},
        {{2, 1, 2}, 2},
        {{10, 1, 1, 10}, 12},
        {{1, 2, 1, 2, 1}, 4}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int got = sol.stoneGameV(tests[i].stones);
        if (got != tests[i].expected) {
            cout << "Test case " << i << " failed\n";
            cout << "Input: ";
            for (int x : tests[i].stones) cout << x << ' ';
            cout << "\nExpected: " << tests[i].expected << "\n";
            cout << "Got: " << got << "\n";
            return 1;
        }
    }

    cout << "All tests passed.\n";
    return 0;
}
