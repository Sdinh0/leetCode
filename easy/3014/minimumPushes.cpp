#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        int lenght = word.length();
        int pushes = 0;
        int i;

        for (i = 0; i < lenght/8; i++)
        {
            pushes += i+1 * 8;
        }
        
        pushes += i+1 * lenght % 8;

        return pushes;
    }
};