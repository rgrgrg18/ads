class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n, 0); // dp[i] - max profit you can have if sell if [i] day
        vector<int> optimal_prev(n, 0); // optimal_prev[i] is the max of (-prices[j] + prev_max[j] - fee) where j < i
        vector<int> prev_max(n, 0); // prev_max[i] = max(dp[0], dp[1] ... dp[i])
        optimal_prev[0] = -prices[0] - fee;
        for (int i = 1; i < n; i++) {
            dp[i] = prices[i] + optimal_prev[i - 1];
            prev_max[i] = max(prev_max[i - 1], dp[i]);
            optimal_prev[i] = max(prev_max[i] - prices[i] - fee, optimal_prev[i - 1]);
        }
        return prev_max.back();
    }
};
