class Solution {
public:
    int findMin(vector<int> &nums) {
        // Use binary search
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            // Compare the mid num with the left and right ones
            int ln = nums[left], rn = nums[right], mn = nums[mid];

            if (mn > rn) {
                // Search the right hand side
                left = mid + 1;
            } else {
                // Search the left hand side
                right = mid;
            } 
        }

        return nums[left];
    }
};
