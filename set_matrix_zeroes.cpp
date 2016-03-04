class Solution {

public:

    void setZeroes(vector<vector<int>>& matrix) {

        int nrows = matrix.size();

        

        if (nrows == 0) {

            return;

        }

        int ncols = matrix[0].size();

        

        bool isFirstColHasZero = false;



        // contains the col index in the first row that has zeros

        int rowInd = -1;

        for (int row=0; row<nrows; row++) {

            for (int col=0; col<ncols; col++) {

                

                if (!matrix[row][col]) {

                    

                    if (-1 == rowInd) {

                        rowInd = row;

                    }

                    matrix[row][0] = 0;

                    matrix[rowInd][col] = 0;

                    

                    if (col == 0) {

                        isFirstColHasZero = true;

                    }

                }

            }

        }

        

        if (rowInd == -1) {

            return;

        }

        // set the col to zero, left the first col 

        for (int col=1; col<ncols; col++) {

            if (!matrix[rowInd][col]) {

                // set col to zero

                for (int row=0; row<nrows; row++) {

                    matrix[row][col] = 0;

                }

            }

        }

        // set the row to zero

        for (int row=0; row<nrows; row++) {

            if (!matrix[row][0]) {

                for (int col=0; col<ncols; col++) {

                    matrix[row][col] = 0;

                }

            }

        }

        // the first col

        if (isFirstColHasZero) {

            matrix[0][0] = 3;

            for (int row=0; row<nrows; row++) {

                matrix[row][0] = 0;

            }

        }

    }

};
