class Solution {
private:
    void dfs(int i, int y, vector<vector<char>>& board, int nrows, int ncols) {
        board[i][j] = '+';
        // no need to consider the peripheral border, so the condition
        // is i > 1, i < rows - 2, not i > 0, i < rows - 1.
        //
        // if use i > 0, i < rows - 1, DFS solution will get a Runtime Error, stack overflow
        if (i > 1 && board[i - 1][j] == 'O')
            dfs(i-1, j, board, nrows, ncols);
        if (i < nrows - 2 && board[i + 1][j] == 'O')
            dfs(i+1, j, board, nrows, ncols);
        if (j > 1 && board[i][j - 1] == 'O')
            dfs(i, j-1, board, nrows, ncols);
        if (j < ncols - 2 && board[i][j + 1] == 'O')
            dfs(i, j+1, board, nrows, ncols);
    }
public:
    void solve(vector<vector<char>>& board) {
       int nrows = board.size();
       if (nrows < 3) return;
       int ncols = board[0].size();
       if (ncols < 3) return;
       
       // if the four side dfs stop, means inner should all turn to X
       // we can reduce many iterator
       for (int col = 0; col < ncols; ++col) {
            if (board[0][col] == 'O')
                dfs(0, col, board, nrows, ncols);
            if (board[nrows - 1][col] == 'O')
                dfs(nrows-1, col, board, nrows, ncols);
        }
        for (int row = 1; row < nrows - 1; ++row) {
            if (board[row][0] == 'O')
                dfs(row, 0, board, nrows, ncols);
            if (board[row][ncols - 1] == 'O')
                dfs(row, ncols-1, board, nrows, ncols);
        }
        for (int row = 0; row < nrows; ++row) {
            for (int col = 0; col < ncols; ++col) {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';
                else if (board[row][col] == '+')
                    board[row][col] = 'O';
            }
        }
    }
};
