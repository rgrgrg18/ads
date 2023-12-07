class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp = 0;
        int prev_max = 0;
        int optimal_prev = -prices[0] - fee;
        for (int i = 1; i < prices.size(); i++) {
            dp = prices[i] + optimal_prev;
            prev_max = max(prev_max, dp);
            optimal_prev = max(prev_max - prices[i] - fee, optimal_prev);
        }
        return prev_max;
    }
};
