#include <iostream>

using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    int res = 0;
    for (long long m=1; m<=n; m*=10) {
      int a = n/m, b=n%m;

      // n = xyzpqr  m = 1000
      // a = xyz  b = pqr
      // if z=0   ones += xyz * 100
      // if z=1   ones += xyz * 100 + pqr + 1
      // if z>2   ones += xyz * 100 + 1000
      // ones += (xyz + 8)*100 + (pqr+1)*(z%10 == 1)
      res += (a + 8)/10 * m + (b + 1) * (a%10 == 1);
    }

    return res;
  }
};

int main()
{
  Solution s;


  cout << (s.countDigitOne(13) == 6) << endl;
  return 0;
}
