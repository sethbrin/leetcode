class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0) return 0;
        if (size == 1) {
            if (s[0] > '0') return 1;
            return 0;
        }
        
        int dp[size+2];
        int i = size;
        dp[size+1] = 0;
        dp[size] = 0;
        while (i >= 0 && s[i] == '0') {
            dp[i] = 0;
            i --;
        }
        dp[i--] = 1;
        for (; i>=0; i--) {
            int one = s[i] - '0';
            int two = 0;
            if (one > 0) {
              two = (s[i]-'0') * 10 + s[i+1] - '0';
            }
            
            dp[i] = (one > 0 ? dp[i+1] : 0) + ((two > 0 && two < 27) ? dp[i+2] : 0);
        }
        return dp[0];
    }
};
