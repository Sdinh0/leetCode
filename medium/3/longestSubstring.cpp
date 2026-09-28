#include <string>
#include <algorithm>
#include <unordered_map> // Include necessary header for map/hash table

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Use a map to store the last seen index of each character.
        std::unordered_map<char, int> charIndexMap;
        int maxLen = 0;
        int start = 0; // Start of the current non-repeating substring window

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // Check if the character was seen AND if its last position is within the current window [start, end]
            if (charIndexMap.count(currentChar) && charIndexMap[currentChar] >= start) {
                // Repetition found within the current window.
                // We must move the starting point (start) immediately past the previous occurrence of this character.
                start = charIndexMap[currentChar] + 1;
            }

            // Update the last seen index for the current character
            charIndexMap[currentChar] = end;

            // The current window length is (end - start + 1)
            maxLen = std::max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};