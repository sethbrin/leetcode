class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int wordsCnt = words.size();
        if (words.empty() || wordsCnt < 2) return res;
        
        unordered_map<string, int> dict;
        // add the reverse of the word into map
        for (int i = 0; i < wordsCnt; i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            
            dict[key] = i;
        }
        
        // check if has ""
        if (dict.find("") != dict.end()) {
            int blankIndex = dict[""];
            for (int i = 0; i < wordsCnt; i++) {
                if (blankIndex == i) continue;
                if (isPalindrome(words[i])) {
                    res.push_back({blankIndex, i}); // blank + word
                }
            }
        }
        
        // find the left | right | word
        // word | left | right
        // check if left == word and right is palindrome
        for (int i = 0; i < wordsCnt; i++) {
            // <= contains that word == ""
            for (int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                
                if (isPalindrome(left)) {
                    if (dict.find(right) != dict.end() && dict[right] != i) {
                        res.push_back({dict[right], i});
                    }
                }
                if (isPalindrome(right)) {
                    if (dict.find(left) != dict.end() && dict[left] != i) {
                        res.push_back({i, dict[left]});
                    }
                }
            }
        }
        
        return res;
    }
    
private:
    bool isPalindrome(const string& word) {
        int start = 0;
        int end = word.size() - 1;
        while (start < end) {
            if (word[start] == word[end]) {
                start ++;
                end --;
            } else {
                return false;
            }
        }
        return true;
    }
};
