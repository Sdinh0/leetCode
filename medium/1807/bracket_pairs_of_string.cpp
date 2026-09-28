#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> knowledgeMap;
        for (const auto& pair : knowledge) {
            knowledgeMap[pair[0]] = pair[1];
        }

        while (s.find('(') != string::npos) {
            size_t start = s.find('(');
            size_t end = s.find(')', start);
            string key = s.substr(start + 1, end - start - 1);

            string value = knowledgeMap.count(key) ? knowledgeMap[key] : "?";
            s = s.substr(0, start) + value + s.substr(s.size() - (s.size() - end - 1));
        }

        return s;
    }
};