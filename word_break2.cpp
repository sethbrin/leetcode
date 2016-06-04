class Solution {
private:
    unordered_map<int, bool> m;
    bool wordBreak(const string& s, int start, unordered_set<string>& wordDict,
        vector<string>& path, vector<string>& res) {
        int size = s.size();
        if (start == size) {
            if (path.empty()) return false;
            string tmp = path[0];
            for (int i = 1; i < path.size(); i++) {
                tmp += (" " + path[i]);
            }
            res.push_back(tmp);
            
            return true;
        }
        
        bool flag = false;
        for (int i = start + 1; i <= size; i++) {
            string word = s.substr(start, i - start);
            if ((m.find(i) == m.end() || m[i]) && wordDict.find(word) != wordDict.end()) {
                path.push_back(word);
                if (wordBreak(s, i, wordDict, path, res)) flag = true;
                path.pop_back();
            }
        }
        
        m[start] = flag;
        return flag;
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty()) {
            return res;
        }
        
        vector<string> path;
        wordBreak(s, 0, wordDict, path, res);
        return res;
    }
};
