class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // grady algorithm
        int res = 0;
        int len = nums.size();
        long total = 1;
        long i=0;
        while (total <= n) {
            if (i >= nums.size() || total < nums[i]) {
                res += 1;
                total = total << 1;
            } else {
                total += nums[i++];
            }
        }
        
        return res;
    }
};
