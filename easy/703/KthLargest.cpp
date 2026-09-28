#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> lastKElements;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (auto i : nums)
        {
            add(i);
        }
        
    }

    int add(int val) {
        if (lastKElements.size() < k)
        {
            lastKElements.push(val);
        }
        else if (lastKElements.top() < val)
        {
            lastKElements.pop();
            lastKElements.push(val);
        }
        
        return lastKElements.top();
    }
};