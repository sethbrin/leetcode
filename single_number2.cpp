class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        int res = 0;
        for (int i=0; i<32; i++) {
            for (int num : nums) {
                if ((num >> i) & 1) {
                    count[i] ++;
                }
            }
            if (count[i] % 3 == 1) {
                res += 1<<i;
            }
        }
        return res;
    }
};
