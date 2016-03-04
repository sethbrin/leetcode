class Solution {

public:

    void getSpiralOneCicle(vector<int>& res, int start, int nrows, int ncols, vector<vector<int>>& matrix) {

        // get the top side

        if (nrows ==0 || ncols == 0) {

            return;

        }

        int row = start;

        int col = start;

        for (int i=0; i<ncols; i++) {

            res.push_back(matrix[row][col]);

            col ++;

        }

        col --;

        if (nrows == 1) {

            return;

        }

        

        // get the right side

        for (int i=0; i<nrows-1; i++) {

            row ++;

            res.push_back(matrix[row][col]);

        }



        // get the bottom side

        for (int i=0; i<ncols-1; i++) {

            col --;

            res.push_back(matrix[row][col]);

        }

        if (ncols == 1) {

            return;

        }

        for (int i=0; i<nrows-2; i++) {

            row --;

            res.push_back(matrix[row][col]);

        }

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        int row = matrix.size();

        if (row == 0) {

            return res;

        }

        int col = matrix[0].size();

        

        int minDimension = min(row, col);

        for (int i=0; i<minDimension; i++) {

            getSpiralOneCicle(res, i, row-i*2, col-i*2,matrix);

        }

        

        return res;

    }

};


