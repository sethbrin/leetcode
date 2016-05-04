class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int size = beginWord.size();
        if (size == 0) return 0;
        // use bfs
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordList.erase(beginWord);
        
        while(!q.empty()) {
            auto front = q.front();
            string word = front.first;
            q.pop();
            
            for (int i=0; i<word.size(); i++) {
                for (char ch='a'; ch<='z'; ch++) {
                    char tmp = word[i];
                    if (tmp != ch) {
                        word[i] = ch;
                        
                        if (word == endWord) return front.second + 1;
                        
                        if (wordList.find(word) != wordList.end()) {
                            q.push({word, front.second + 1});
                            // the later word should not be word
                            // Also can use a visited set to store the visited words
                            wordList.erase(word);
                        }
                        word[i] = tmp;
                    }
                }
            }
        }
        
        return 0;
    }
};
