class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        dp = new int[n+1];
        // dp[i] means the least number of perfect square numbers which sums to i
        dp[1] = 1;
        dp[2] = 2;
        int curSqrt = 2;
        // dp[n] = min{(dp[n-1) + dp[1]), (dp[n-2] + dp[2])....}
        for (int i=3; i<=n ;i++) {
            int minNum = INT_MAX;
            if (i == curSqrt * curSqrt) {
                minNum = 1;
                curSqrt ++;
            } else {
                for (int j=curSqrt-1; j>=1; j--) {
                    minNum = min(minNum, dp[j*j] + dp[i-j*j]);
                }
            }
            dp[i] = minNum;
        }
       
        return dp[n];
    }
private:
    int* dp;
};
