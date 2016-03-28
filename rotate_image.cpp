class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        rotate(matrix, 0, n);
    }
private:
    void rotate(vector<vector<int>>& matrix, int start, int n) {
        if (n - 2*start < 2) {
            return;
        }
        
        for (int i=start; i<n-start-1; i++) {
            swap(matrix[start][i], matrix[i][n-start-1]);
            swap(matrix[start][i], matrix[n-start-1][n-i-1]);
            swap(matrix[start][i], matrix[n-i-1][start]);
            
        }
        
        rotate(matrix, start + 1, n);
    }
};
