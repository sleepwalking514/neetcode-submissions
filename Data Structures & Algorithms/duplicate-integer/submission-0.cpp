class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        return numsSet.size() < nums.size();
    }
};