class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }
        vector<int> dp(len, 0);
        // dp[i] indicate that we sell stock at day i, we can get the maximum profit
        dp[0] = 0;
        dp[1] = prices[1] - prices[0];
        for (int i=2; i<len; i++) {
            int tmp = prices[i] - prices[i-1];
            dp[i] = dp[i-1] < 0?tmp:(dp[i-1] + tmp);
        }

        return *max_element(dp.begin(), dp.end());

    }

};
