#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_set<string> visitedList;
        queue<vector<string>> q;
        q.push({beginWord});
        visitedList.insert(beginWord);
        vector<vector<string>> res;
        
        int size = beginWord.size();
        int minLevel = 0;
label:
        while (!q.empty()) {
            vector<string> path = q.front();
            string curStr = path.back();
            visitedList.insert(curStr);
            cout << "===pop==" << endl;
            cout << "qsize:" << q.size() << endl;
            copy(path.begin(), path.end(), ostream_iterator<string>(cout, " "));
            cout << endl;
            q.pop();
            int level = path.size() + 1;
            if (minLevel != 0 && minLevel < level) {
              continue;
            }
            for (int i=0; i<size; i++) {
                for (char ch='a'; ch<='z'; ch++) {
                    char tmp = curStr[i];
                    curStr[i] = ch;
                    path.push_back(curStr);
                    if (curStr == endWord) {
                        if (minLevel == 0) {
                            minLevel = level;
                            
                            res.push_back(path);
                        } else {
                          res.push_back(path);
                        }
                    } else {
                        if (wordList.find(curStr) != wordList.end() 
                            && visitedList.find(curStr) == visitedList.end()) {
                            q.push(path);
                        }
                    }
                    curStr[i] = tmp;
                    path.pop_back();
                }
            }
            visitedList.erase(curStr);
        }
        
        return res;
    }
};

int main() {
  string beginWord = "red";
  string endWord = "tax";
  unordered_set<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};

  Solution s;
  s.findLadders(beginWord, endWord, wordList);
  return 0;
}
