class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Traverse from right to left to find highest on the right
        int n = prices.size();
        int h = 0, p = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (prices[i + 1] > h) h = prices[i + 1];

            // Update max profit
            p = max(p, h - prices[i]);
        }

        return p;
    }
};
