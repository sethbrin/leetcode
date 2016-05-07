class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if (rows == 0) return res;
        int cols = matrix[0].size();
        if (cols == 0) return res;
        
        for (int r=0, c=0; r < (rows+1)/2 && c < (cols+1)/2; c++, r++) {
            // top
            for (int i=c; i<cols-c; i++) res.push_back(matrix[r][i]);
            // right
            for (int i=r+1; i<rows-r; i++) res.push_back(matrix[i][cols-c-1]);
            // bottom
            // As rows-r-1 is cover by the right
            for (int i=cols-c-2; rows-r-1>r && i>=c; i--) res.push_back(matrix[rows-r-1][i]);
            // left
            for (int i=rows-r-2; cols-c-1>c && i>=r+1; i--) res.push_back(matrix[i][c]);
        }
        
        return res;
    }
};
