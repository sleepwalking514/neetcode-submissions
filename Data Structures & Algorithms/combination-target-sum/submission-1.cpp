class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> record;
        search(ans, nums, record, 0, target);
        return ans;
    }

    void search(
        vector<vector<int>>& ans, \
        vector<int>& nums, vector<int>& record, \
        int start, int left
    ) {
        if (left == 0) {
            ans.emplace_back(record);
            return;
        }
        if (left < 0) return;

        for (int i = start; i < nums.size(); ++i) {
            int num = nums[i];
            
            record.emplace_back(num);
            search(ans, nums, record, i, left - num);
            record.pop_back();
        }
    }
};
