class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<pair<int, int>> bounds;
        int maxLen = 0;

        for (const auto& n: nums) {
            bool formed = false;
            for (int i = 0; i < bounds.size(); i++) {
                auto [left, right] = bounds[i];

                // form a group
                if (left - 1 <= n && n <= right + 1) {
                    if (n == left - 1) {
                        left--;
                    } else if (n == right + 1) {
                        right++;
                    }
                    maxLen = max(maxLen, right - left + 1);
                    bounds[i] = {left, right};
                    formed = true;
                    break;
                }
            }
            // form a new group
            if (!formed) {
                bounds.push_back({n, n});
                maxLen = max(maxLen, 1);
            }
        }

        // combine bounds
        for (int i = 0; i < bounds.size() - 1; i++) {
            auto [iLeft, iRight] = bounds[i];
            for (int j = i + 1; j < bounds.size(); j++) {
                auto [jLeft, jRight] = bounds[j];
                if (jLeft <= iRight + 1 && jRight >= iRight + 1 ||
                    jLeft <= iLeft - 1 && jRight >= iLeft - 1) {
                    int left = min(iLeft, jLeft), right = max(iRight, jRight);
                    maxLen = max(maxLen, right - left + 1);
                    bounds[i] = bounds[j] = {left, right};
                }
            }
        }

        return maxLen;
    }   
};