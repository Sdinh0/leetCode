using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long rangeStart = 1000;
        
        while (rangeStart <= n)
        {
            commas += n - rangeStart + 1;

            if (rangeStart > n / 1000)
            {
                break;
            }

            rangeStart *= 1000;
            
        }
        return commas;
    }
};