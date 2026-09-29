#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        sort(knowledge.begin(), knowledge.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0];
             });

        string result;
        result.reserve(s.size());

        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != '(') {
                result.push_back(s[i]);
                continue;
            }

            size_t end = s.find(')', i + 1);
            string_view key(s.data() + i + 1, end - i - 1);

            auto it = lower_bound(
                knowledge.begin(), knowledge.end(), key,
                [](const vector<string>& entry, string_view sought) {
                    return string_view(entry[0]) < sought;
                });

            if (it != knowledge.end() && string_view((*it)[0]) == key) {
                result += (*it)[1];
            } else {
                result.push_back('?');
            }

            i = end;
        }

        return result;
    }
};