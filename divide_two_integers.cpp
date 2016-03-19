class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == dividend) {
            return 0;
        }

        if (0 == divisor) {
            return INT_MAX;
        }

        if (1 == divisor) {
            return dividend;
        }

        if (INT_MIN == dividend) {
            if (-1 == divisor) {
                return INT_MAX;
            }
        }

        unsigned int absDividend = dividend;
        unsigned int absDivisor = divisor;
        if (dividend < 0) absDividend = -dividend;
        if (divisor < 0) absDivisor = - divisor;
        int res = 0;
        // find the k that 2^k * absDivisor <= absDividend < 2^(k+1) * absDivisor
        while (absDivisor <= absDividend) {
            long tmp = absDivisor;
            int k = 0;
            while (tmp <= absDividend) {
                tmp = tmp << 1;
                k ++;
            }
            res += (1 << (k-1));
            absDividend -= (absDivisor << (k-1));
        }
        return (dividend < 0 ^ divisor < 0) ? -res : res;
    }
};
