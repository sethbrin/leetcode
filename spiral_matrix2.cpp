class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return vector<vector<int>>();
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int number = 1;
        for (int m=0; m<(n+1)/2; m++) {
            // top
            for (int i=m; i<n-m; i++) matrix[m][i] = number++;
            // right
            for (int i=m+1; i<n-m; i++) matrix[i][n-m-1] = number++;
            // bottom
            for (int i=n-m-2; i>=m; i--) matrix[n-m-1][i] = number++;
            // left
            for (int i=n-m-2; i>m; i--) matrix[i][m] = number++;
        }
        return matrix;
    }
};
