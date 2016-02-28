#include <climits>

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n == INT_MIN) {
      if (x == 1 || x == -1) {
        return 1;
      }
      return 0;
    }
    double res = 1;
    bool signOfN = n > 0;
    n = n>0?n:(-n);

    double ans[32]; // store x^(2^i)(-1<i<32)
    ans[0] = x;

    for (int i=1; i<32; i++) {
      res *= ((n&1) ? ans[i-1] : 1);
      n = n >> 1;
      ans[i] = ans[i-1] * ans[i-1];
    }

    if (!signOfN) {
      res = 1 / res;
    }
    return res;

  }

};
