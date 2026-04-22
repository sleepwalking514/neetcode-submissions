class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int count = 1;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                pq.push({count, nums[i - 1]});
                count = 1;
            }
        }
        // Handle the last element
        pq.push({count, nums.back()});

        vector<int> ans;
        for (int i = 0; i < k && !pq.empty(); i++) {
            auto [value, num] = pq.top();
            ans.push_back(num);
            pq.pop();
        }

        return ans;
    }
};
