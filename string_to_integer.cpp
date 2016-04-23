// consider
// 1. sign
// 2. string larger than INT_MAX
// 3. string less than INT_MIN
// 4. string like "  123abc" should return 123
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        
        int len = str.size();
        
        char sign = 1;
        // skip the blank
        int ind = 0;
        char ch;
        while (ind < len && str[ind] == ' ') {
            ind ++;
        }
        ch = str[ind++];
        if (ch == '-') {
            sign = -1;
        } else if (isdigit(ch)) {
            res = (ch - '0');
        } else if (ch == '+') {
            sign = 1;
        } else {
            return 0;
        }
        while (ind < len) {
            ch = str[ind++];
            if (isdigit(ch)) {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (ch - '0') > INT_MAX % 10)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                res = res * 10 + (ch - '0');
                
            } else {
                break;
            }
        }
        res = res * sign;
        
        return res;
    }
};
