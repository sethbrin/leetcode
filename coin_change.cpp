class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;

        int dp[amount+1];
        dp[0] = 0;
        int tmp;

        for (int i=1; i<=amount; i++) {
            tmp = INT_MAX;

            for (int money: coins) {
                if (i >= money && dp[i-money] != -1) {
                    tmp = min(tmp, dp[i - money] + 1);
                }
            }

            dp[i] = tmp == INT_MAX ? -1 : tmp;
        }
        return dp[amount];
    }
};
