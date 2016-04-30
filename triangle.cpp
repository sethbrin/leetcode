class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (rows == 0) return 0;
        
        int dp[rows];
        dp[0] = triangle[0][0];
        
        for (int i=1; i<rows; i++) {
            dp[i] = dp[i-1] + triangle[i][i];
            
            for (int j=i-1; j>0; j--) {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        
        return *min_element(dp, dp+rows);
    }
};
