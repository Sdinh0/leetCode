#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        const vector<string> letters = {"", "", "abc",  "def",
            "ghi", "jkl", "mno",  "pqrs",
            "tuv", "wxyz"
        };

        vector<string> result;
        string current;

        function<void(int)> combinations = [&](int index) {
            if (index == digits.size())
            {
                result.push_back(current);
                return;
            }
            
            string buttonLetters = letters[digits[index] - '0'];

            for (char letter : buttonLetters)
            {
                current.push_back(letter);
                combinations(index+1);
                current.pop_back();
            }
            
        };

        combinations(0);

        return result;
    }
};