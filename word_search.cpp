class Solution {
private:

    bool dfs(const vector<vector<char>>& board, const string& word, int index, int x, int y, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if (board[x][y] != word[index] || visited[x][y]) return false;

        visited[x][y] = true;
        bool res =  dfs(board, word, index+1, x-1, y, visited) // top
            || dfs(board, word, index+1, x+1, y, visited) // bottom
            || dfs(board, word, index+1, x, y-1, visited) // left
            || dfs(board, word, index+1, x, y+1, visited); // right;

        visited[x][y] = false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        if (cols == 0) return false;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (dfs(board, word, 0, i, j, visited)) return true;
            }
        }

        return false;
    }
};
