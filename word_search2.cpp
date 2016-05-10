class Solution {
private:
    typedef struct Node {
        char val;
        struct Node* childs[26];
        bool isWord;
        int index; // the word index
        Node(char ch) : val(ch), isWord(false) {
            for (int i=0; i<26; i++) childs[i] = NULL;
        }
    } Node;
    
    void addNode(Node* root, const string& word, int index) {
        for (char ch : word) {
            Node*& child = root->childs[ch - 'a'];
            if (child == NULL) {
                child = new Node(ch);
            }
            
            root = child;
        }
        root->isWord = true;
        root->index = index;
    }
    
    Node* buildTrie(vector<string>& words) {
        Node* root = new Node(0);
        for (int i=0; i<words.size(); i++) {
            addNode(root, words[i], i);
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board, int row, int col, vector<string>& res, vector<string>& words, Node* root) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (root == NULL) return;
        if (row < 0 || row >= rows || col < 0 || col >= cols) return;
        if (board[row][col] == 'X') return;
        
        char tmp = board[row][col];
        
        if (root->childs[tmp - 'a'] == NULL) return;
        root = root->childs[tmp - 'a'];
        if (root->isWord) {
            res.push_back(words[root->index]);
            root->isWord = false; // set the we have find the word already
        }
        
    
        board[row][col] = 'X';
        dfs(board, row-1, col, res, words, root);
        dfs(board, row+1, col, res, words, root);
        dfs(board, row, col-1, res, words, root);
        dfs(board, row, col+1, res, words, root);
        board[row][col] = tmp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // use trie tree
        vector<string> res;
        int rows = board.size();
        if (rows == 0) return res;
        int cols = board[0].size();
        if (cols == 0) return res;
        if (words.size() == 0) return res;
        
        Node* root = buildTrie(words);
        
        for (int row=0; row<rows; row++) {
            for (int col=0; col<cols; col++) {
                dfs(board, row, col, res, words, root);
            }
        }
        
        return res;
    }
};
