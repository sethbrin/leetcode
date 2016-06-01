class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        if (cols == 0) return;
        
        // only if the cell is LIVE and TURNTODEAD, we count 
        // the two number is odd
        const int ISLIVE = 0x1;
        const int IASDEAD = 0x0;
        const int TURNTODEAD = 0x3;
        const int TURNTOLIVE = 0x2;
        
        for (int row = 0; row < rows; row ++) {
            for (int col = 0; col < cols; col ++) {
                // check cell (row, col)
                int cnt = 0;
                if ((row - 1 >= 0 && col - 1 >= 0) && board[row-1][col-1] & 1 == 1) cnt++;
                if ((row - 1 >= 0) && board[row-1][col] & 1 == 1) cnt++;
                if ((row - 1 >= 0 && col + 1 < cols) && board[row-1][col+1] & 1 == 1) cnt++;
                if ((col - 1 >= 0) && board[row][col-1] & 1 == 1) cnt++;
                if ((col + 1 < cols) && board[row][col+1] & 1 == 1) cnt++;
                if ((row + 1 < rows && col - 1 >= 0) && board[row+1][col-1] & 1 == 1) cnt++;
                if ((row + 1 < rows) && board[row+1][col] & 1 == 1) cnt++;
                if ((row + 1 < rows && col + 1 < cols) && board[row+1][col+1] & 1 == 1) cnt++;
                
                if (board[row][col] == ISLIVE) {
                    if (cnt < 2 || cnt > 3) board[row][col] = TURNTODEAD;
                } else {
                    if (cnt == 3) board[row][col] = TURNTOLIVE;
                }
                // check cell (row-1, col-1), and modify its state
                if (row - 1 >= 0 && col - 1 >= 0) {
                    if (board[row-1][col-1] == TURNTODEAD) board[row-1][col-1] = 0;
                    if (board[row-1][col-1] == TURNTOLIVE) board[row-1][col-1] = 1;
                }
            }
            // the last row will check 2 cols
            if (row - 1 >= 0) {
                if (board[row-1][cols-1] == TURNTODEAD) board[row-1][cols-1] = 0;
                if (board[row-1][cols-1] == TURNTOLIVE) board[row-1][cols-1] = 1;
            }
        }
        // the last row
        for (int col = 0; col < cols; col++) {
            if (board[rows-1][col] == TURNTODEAD) board[rows-1][col] = 0;
            if (board[rows-1][col] == TURNTOLIVE) board[rows-1][col] = 1;
        }
        return;
    }
};
