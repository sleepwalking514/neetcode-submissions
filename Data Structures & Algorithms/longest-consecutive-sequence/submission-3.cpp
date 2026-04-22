class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (auto num: numSet) {
            // find the beginning of a sequence
            if (!numSet.contains(num - 1)) {
                int curLen = 1;

                // search for the entire sequence
                while (numSet.contains(num + 1)) {
                    num++;
                    curLen++;
                }
                maxLen = max(maxLen, curLen);
            }
        } 

        return maxLen;
    }   
};