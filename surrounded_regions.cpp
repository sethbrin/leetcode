class Solution {
private:
    void bfs(int i, int j, vector<vector<char>>& board, int nrows, int ncols) {
        board[i][j] = '+';
        // no need to consider the peripheral border, so the condition
        // is i > 1, i < rows - 2, not i > 0, i < rows - 1.
        //
        // if use i > 0, i < rows - 1, also accept
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            int row = cur.first;
            int col = cur.second;
            q.pop();
            
            if (row > 1 && board[row-1][col] == 'O') {
                board[row-1][col] = '+';
                q.push({row-1, col});
            }
            if (row < nrows-2 && board[row+1][col] == 'O') {
                board[row+1][col] = '+';
                q.push({row+1, col});
            }
            if (col > 1 && board[row][col-1] == 'O') {
                board[row][col-1] = '+';
                q.push({row, col-1});
            }
            if (col < ncols - 1 && board[row][col+1] == 'O') {
                board[row][col+1] = '+';
                q.push({row, col+1});
            }
           
        }
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
                bfs(0, col, board, nrows, ncols);
            if (board[nrows - 1][col] == 'O')
                bfs(nrows-1, col, board, nrows, ncols);
        }
        for (int row = 1; row < nrows - 1; ++row) {
            if (board[row][0] == 'O')
                bfs(row, 0, board, nrows, ncols);
            if (board[row][ncols - 1] == 'O')
                bfs(row, ncols-1, board, nrows, ncols);
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
