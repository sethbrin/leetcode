class Solution {

public:

    int integerBreak(int n) {
        int dp[n+1];

        dp[2] = 1;
        dp[3] = 2;

        for (int i=4; i<=n; i++) {
            dp[i] = 0;
            for (int j=2; j<=i/2; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(dp[i-j], i-j));
            }
        }

        return dp[n];
    }
};
