class Solution {

public:

    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int res = INT_MIN;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                int tmp = matrix[i][j] - '0';
                if (i == 0 || j == 0) dp[i][j] = tmp == 1;
                else if (tmp == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }

                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
