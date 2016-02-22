#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    int total = 0;
    stack<int> signs;
    signs.push(1);
    signs.push(1);
    for (int i=0; i<s.size(); i++) {
      char c = s[i];
      if (c >= '0') {
        int number = 0;
        while (i < s.size()  &&  s[i] >= '0')
          number = 10 * number + s[i++] - '0';
        total += signs.top() * number;
        signs.pop();
        i--;
      }
      else if (c == ')')
        signs.pop();
      else if (c != ' ')
        signs.push(signs.top() * (c == '-' ? -1 : 1));
    }
    return total;
  }
};

int main()
{
  Solution s;

  // 46.76%
  cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
  return 0;
}
