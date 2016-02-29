#include <vector>
using namespace std;

class Solution {
public:
    int longestPath(vector<vector<int> >& matrix, vector<vector<int> >& res, int i, int j, int nrows, int ncols) {
        if (res[i][j] > 0) {
            return res[i][j];
        }
        int maxDirection = 0;
        if (i > 0 && matrix[i][j] > matrix[i-1][j]) {
            maxDirection = max(maxDirection, longestPath(matrix, res, i-1, j, nrows, ncols) );
        }
        if (j > 0 && matrix[i][j] > matrix[i][j-1]) {
            maxDirection = max(maxDirection, longestPath(matrix, res, i, j-1, nrows, ncols));
        }
        if (i < nrows-1 && matrix[i][j] > matrix[i+1][j]) {
            maxDirection = max(maxDirection, longestPath(matrix, res, i+1, j, nrows, ncols));
        }
        if (j < ncols-1 && matrix[i][j] > matrix[i][j+1]) {
            maxDirection = max(maxDirection, longestPath(matrix, res, i, j+1, nrows, ncols));
        }

        res[i][j] = maxDirection + 1;

        return res[i][j];
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int nrows = matrix.size();
        if (nrows == 0) {
            return 0;
        }
        int ncols = matrix[0].size();
        int res;

        vector<vector<int> > dp(nrows, vector<int>(ncols, 0));

        for (int i=0; i<nrows; i++) {
            for (int j=0; j<ncols; j++) {
                res = max(res, longestPath(matrix, dp, i, j, nrows, ncols));
            }
        }
        return res;
    }
};
