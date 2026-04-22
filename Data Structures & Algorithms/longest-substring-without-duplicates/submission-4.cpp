#include <cstring>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Best sln: record the last index of each character
        int lastIdx[128]; // Enough for ascii
        memset(lastIdx, -1, sizeof(lastIdx));
        int maxLen = 0;
        int left = 0, right = -1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (lastIdx[c] >= left) {
                // Update max length
                maxLen = max(maxLen, right - left + 1);
                // Move left to the right of the duplicate char
                left = lastIdx[c] + 1;
            }
            // Add new char
            lastIdx[c] = i;
            right++;
        }

        return max(maxLen, right - left + 1);
    }
};
