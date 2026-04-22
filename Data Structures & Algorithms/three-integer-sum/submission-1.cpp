class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        // Fix the leftmost index
        for (int i = 0; i < n - 2; i++) {
            int target = -nums[i];

            // Init and move the left and right pointers
            int j = i + 1, k = n - 1;
            // Prune
            if (nums[j] + nums[j + 1] > target) break;

            while (j < k) {
                // Prune
                if (nums[j] + nums[j + 1] > target ||
                    nums[k] + nums[k - 1] < target) {
                    break;
                }
                if (nums[j] + nums[k] > target) {
                    // Larger than target, move k
                    while (j < k && nums[k] == nums[--k]);
                } else if (nums[j] + nums[k] < target) {
                    // Smaller than target, move j
                    while (j < k && nums[j] == nums[++j]);
                } else {
                    // Find an triple and move j, k
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[++j]);
                    while (j < k && nums[k] == nums[--k]);
                }
            }

            // Skip the duplicate numbers
            while (i < n - 3 && nums[i] == nums[i + 1]) {i++;}
        }

        return res;
    }
};
