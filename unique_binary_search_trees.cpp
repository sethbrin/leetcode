class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) return 0;
    
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        
        for (int j=2; j<=n; j++) {
            for (int i=1; i<=j; i++) {
                dp[j] += dp[i-1] * dp[j-i];
            }
        }
        
        return dp[n];
    }
};
