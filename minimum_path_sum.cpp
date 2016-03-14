class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrows = grid.size();
        if (nrows == 0) {
            return 0;
        }
        int ncols = grid[0].size();
        
        vector<vector<int>> dp(nrows, vector<int>(ncols, 0));
        // fill the first row and first col
        int sum = 0;
        for (int i=0; i<ncols; i++) {
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        sum = 0;
        for (int i=0; i<nrows; i++) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        
        for (int i=1; i<nrows; i++) {
            for (int j=1; j<ncols; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[nrows-1][ncols-1];
    }
};
