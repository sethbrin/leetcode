#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start ++;
            end --;
        }
        return true;
    }
    
    vector<vector<string> > partition(const string& s, int start, int end) {
        vector<vector<string> > res;
        if (start == end) {

          vector<string> tmp;
          tmp.push_back(s.substr(start, end-start+1));
            res.push_back(tmp);
            return res;
        }
        
        for (int i=start; i<end; i++) {
            vector<vector<string> > left = partition(s, start, i);
            vector<vector<string> > right = partition(s, i+1, end);
            
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    vector<string> tmp(left[j].begin(), left[j].end());

                    tmp.insert(tmp.end(), right[k].begin(), right[k].end());
                    res.push_back(tmp);
                }
            }
        }
        if (isPalindrome(s, start, end)) {
          vector<string> tmp;
          tmp.push_back(s.substr(start, end-start+1));
            res.push_back(tmp);
        }
        
        return res;
    }
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        if (s.size() == 0) return res;
        
        res = partition(s, 0, (int)s.size() - 1);
        
        return res;
    }
};

int main()
{
  string str = "aab";

  Solution s;
  vector<vector<string> > res = s.partition(str);
  for (int i=0; i<res.size(); i++) {
    copy(res[i].begin(), res[i].end(), ostream_iterator<string>(cout, " "));
    cout << endl;
  }
  return 0;
}
