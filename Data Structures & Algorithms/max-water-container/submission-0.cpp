class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Move two pointers to find max area
        int left = 0, right = heights.size() - 1;
        int area = 0;

        // Idea: move the lower bar
        while (left < right) {
            int lh = heights[left], rh = heights[right];
            if (lh >= rh) {
                area = max(area, rh * (right - left));
                right--;
            } else {
                area = max(area, lh * (right - left));
                left++;
            }
        }

        return area;
    }
};
