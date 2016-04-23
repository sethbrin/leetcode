class Solution {

public:

    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int remainder = n / 3;
        int mod = n - remainder * 3;

        if (mod == 0) {
            return pow(3, remainder);
        } else if (mod == 1){
            return pow(3, remainder - 1) * 4;
        } else {
            return pow(3, remainder) * 2;
        }
    }
};
