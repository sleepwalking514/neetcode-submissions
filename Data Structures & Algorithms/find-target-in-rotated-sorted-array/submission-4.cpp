class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary search
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int ln = nums[left], rn = nums[right], mn = nums[mid];

            if (mn == target) return mid;

            if (mn > rn) {
                // Left part > Right part
                if (target > mn || target < ln) {
                    // Target must be on the right hand side
                    left = mid + 1;
                } else {
                    // Left hand side
                    right = mid - 1;
                }
            } else {
                // Right part > Left part
                if (target < mn || target > rn) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};
