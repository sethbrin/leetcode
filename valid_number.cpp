#include <iostream>

using namespace std;

class Solution {
 public:
  bool isNumber(string s) {
    int ind = 0;
    int len = s.length();

    bool res = true;
    // skip blank
    while (ind<len && s[ind] == ' ') {
      ind++;
    }
    if (s[ind] == '+' || s[ind] == '-') {
      ind ++;
    }
    int digits = 0, dots = 0;
    while (ind < len && ((s[ind] >= '0' && s[ind] <= '9') || s[ind] == '.')) {
      if (s[ind] == '.') {
        dots ++;
      } else {
        digits ++;
      }
      ind ++;
    }
    // decide the digits number and dots number
    if (digits < 1 || dots > 1) {
      return false;
    }
    if (ind == len) {
      return true;
    }

    if (s[ind] == 'e') {
      ind ++;
      if (ind == len) {
        return false;
      }

      if (s[ind] == '+' || s[ind] == '-') {
        ind ++;
      }

      digits = 0;
      while (ind < len && (s[ind] >= '0' && s[ind] <= '9')) {
        digits ++;
        ind ++;
      }
      if (digits < 1) {
        return false;
      }
    }
    // skip blank
    while (ind<len && s[ind] == ' ') {
      ind++;
    }

    return ind == len;
  }
};
int main()
{
  Solution s;

  cout << s.isNumber(" 1 ") << endl;
  return 0;
}
