class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        // store the index in s, which can build a word in dict
        if (wordDict.find(s) != wordDict.end()) return true;
        
        int size = s.size();
        if (size == 0) return false;
        
        // dp[i] donate that if the [0, i) can be segmented into words
        int dp[size + 1];
        dp[0] = true;
        
        for (int i = 1; i <= size; i++) {
            dp[i] = false;
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[size];
    }
};
