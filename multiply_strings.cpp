class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string res(size1 + size2, '0');
        
        for (int i=size1-1; i>=0; i--) {
            int carry = 0;
            for (int j=size2-1; j>=0; j--) {
                int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            res[i] += carry;
        }
        
        size_t pos = res.find_first_not_of('0');
        if (pos != string::npos) {
            return res.substr(pos);
        } else {
            return "0";
        }
        
    }
};
