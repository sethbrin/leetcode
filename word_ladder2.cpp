class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string>> traces; // store the pre word
        
        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        vector<vector<string>> res;
        vector<string> path;
        for (string word: wordList) {
            traces[word] = path;
        }
        
        // store the current layer and prelayer words
        vector<unordered_set<string>> layers(2);
        int pre = 1;
        int cur = 0;
        layers[cur].insert(beginWord);
        
        while (true) {
            cur = !cur;
            pre = !pre;
            
            // erase the visited word
            for (string word: layers[pre]) {
                wordList.erase(word);
            }
            // get the next layer, the pre turn to cur, the cur clear
            layers[cur].clear();
            for (string word: layers[pre]) {
                for (int i=0; i<word.size(); i++) {
                    string tmp = word;
                    for (char ch='a'; ch<='z'; ch++) {
                        tmp[i] = ch;
                        if (wordList.find(tmp) != wordList.end()) {
                            traces[tmp].push_back(word); // we can trace from tmp to word
                            layers[cur].insert(tmp);
                        }
                    }
                }
            }
            
            if (layers[cur].size() == 0) {
                return res; // can not find path
            }
            // find if the current layer contains endWord
            if (layers[cur].find(endWord) != layers[cur].end()) {
                break;
            }
        }
        
        // build Paths
        buildPath(res, path, endWord, beginWord, traces);
        
        return res;
    }
private:
    void buildPath(vector<vector<string>>& res, vector<string>& path, 
        const string& word, const string& beginWord, 
        unordered_map<string, vector<string>>& traces) {
            
        if (word == beginWord) {
            path.push_back(beginWord);
            vector<string> curPath = path;
            reverse(curPath.begin(), curPath.end());
            res.push_back(curPath);
            
            // do not forget pop back
            path.pop_back();
            return;
        }
        
        const vector<string>& preVec = traces[word];
        path.push_back(word);
        for (const string& preWord: preVec) {
            buildPath(res, path, preWord, beginWord, traces);
        }
        path.pop_back();
    }
};
