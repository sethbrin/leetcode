class Solution {
private:
    unordered_map<string, vector<string>> m;
    vector<string> combine(vector<string> res, const string& word) {
        for (string& str : res) {
            str += " " + word;
        }
        return res;
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (m.find(s) != m.end()) return m[s];
        
        vector<string> res;
        if (wordDict.find(s) != wordDict.end()) {
            res.push_back(s);
        }
        
        for (int i = 1; i < s.size(); i++) {
            string newWord = s.substr(i);
            
            if (wordDict.find(newWord) != wordDict.end()) {
                string remStr = s.substr(0, i);
                vector<string> prev = combine(wordBreak(remStr, wordDict), newWord);
                
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        m[s] = res;
        return res;
    }
};
