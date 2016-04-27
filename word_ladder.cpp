class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int size = beginWord.size();
        if (size == 0) return 0;
        // use bfs
        queue<pair<string, int>> q;
        unordered_set<string> visitedList;
        q.push({beginWord, 1});
        visitedList.insert(beginWord);
        
        while (!q.empty()) {
            auto curPair = q.front(); 
            string cur = curPair.first;
            int level = curPair.second;
            q.pop();
            
            for (int i=0; i<size; i++) {
                for (char ch='a'; ch<='z'; ch++) {
                    char tmp = cur[i];
                    cur[i] = ch;
                    if (cur == endWord) {
                        return level+1;
                    } else {
                        if (visitedList.find(cur) == visitedList.end() && wordList.find(cur) != wordList.end()) {
                            q.push({cur, level+1});
                            visitedList.insert(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
        }
        
        return 0;
    }
};
