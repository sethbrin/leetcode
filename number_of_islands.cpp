class Solution {
    void bfs(vector<vector<char>>& grid, int i, int j, int nrows, int ncols) {
        grid[i][j] = '+';
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            
            int row = cur.first;
            int col = cur.second;
            
            if (row >= 1 && grid[row-1][col] == '1') {
                grid[row-1][col] = '+';
                q.push({row-1, col});
            }
            if (row < nrows-1 && grid[row+1][col] == '1') {
                grid[row+1][col] = '+';
                q.push({row+1, col});
            }
            if (col >= 1 && grid[row][col-1] == '1') {
                grid[row][col-1] = '+';
                q.push({row, col-1});
            }
            if (col < ncols-1 && grid[row][col+1] == '1') {
                grid[row][col+1] = '+';
                q.push({row, col+1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int nrows = grid.size();
        if (nrows == 0) return 0;
        int ncols = grid[0].size();
        
        int res = 0;
        for (int i=0; i<nrows; i++) {
            for(int j=0; j<ncols; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, nrows, ncols);
                    res ++;
                }
            }
        }
        
        return res;
        // for (int i=0; i<nrows; i++) {
        //     for(int j=0; j<ncols; j++) {
        //         if (grid[i][j] == '+') {
        //             grid[i][j] = '1';
        //         }
        //     }
        // }
    }
};
