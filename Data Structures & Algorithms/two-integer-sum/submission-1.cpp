class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.contains(nums[i])) {
                return {umap[nums[i]], i};
            }
            umap[target - nums[i]] = i;
        }

        return {0, 0};
    }
};
