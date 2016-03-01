class Solution {
public:
    // find if in the area (0,0) -> (row,col) contains the sub of the word
    bool exist(vector<vector<char>>& board, int row, int col, string word, int ind) {
        if (ind == word.size()) {
            return true;
        }
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[ind]) {
            return false;
        }
        
        // set board[row][col] to a unque char
        board[row][col] = 3;
        
        bool res = exist(board, row-1, col, word, ind+1) ||
               exist(board, row+1, col, word, ind+1) ||
               exist(board, row, col+1, word, ind+1) ||
               exist(board, row, col-1, word, ind+1);
        board[row][col] = word[ind];
        return res;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        // use recursion
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (exist(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
