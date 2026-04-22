class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> us;
        int maxLen = 0;
        int left = 0, right = -1;

        for (const auto c: s) {
            if (us.contains(c)) {
                // Update maxLen
                maxLen = max(maxLen, right - left + 1);
                for (int i = left; i <= right; i++) {
                    us.erase(s[i]);
                    left++;
                    if (s[i] == c) {
                        break;
                    }
                }
            }
            // Add the new char
            us.insert(c);
            right++;
        }

        return max(maxLen, right - left + 1);
    }
};
