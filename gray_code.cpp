class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) {
            return {0};
        }
        if (n == 1) {
            return {0,1};
        }
        long long pow2n1 = pow(2, n-1);
        long long pow2n = 2 * pow2n1;
        vector<int> res(pow2n, 0);
        
        vector<int> graycode = grayCode(n-1);
        for (int i=0; i<pow2n1; i++) {
            res[i] = graycode[i];
            res[pow2n - i - 1] = graycode[i] + pow2n1;
        } 
        
        return res;
    }
};
