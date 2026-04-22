class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary search
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int ln = nums[left], rn = nums[right], mn = nums[mid];

            if (mn > rn) {
                // Left part > Right part
                if (target > mn) {
                    // Target must be on the right hand side
                    left = mid + 1;
                } else if (target < mn) {
                    // Can be on either side, divide further
                    if (target > ln) {
                        // Left hand side
                        right = mid - 1;
                    } else if (target < ln) {
                        // Right hand side
                        left = mid + 1;
                    } else {
                        return left;
                    }
                } else {
                    return mid;
                }
            } else {
                // Right part > Left part
                if (target < mn) {
                    right = mid - 1;
                } else if (target > mn) {
                    if (target < rn) {
                        left = mid + 1;
                    } else if (target > rn) {
                        right = mid - 1;
                    } else {
                        return right;
                    }
                } else {
                    return mid;
                }
            }
        }

        return -1;
    }
};
