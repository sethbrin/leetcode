class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return size;
        }

        vector<int> newNums(size, 0);
        int res = 1;
        newNums[0] = nums[0];
        bool exists = false;
        for (int i=1; i<size; i++) {
            if (nums[i] == nums[i-1]) {
                if (!exists) {
                    newNums[res++] = nums[i];
                }
                exists = true;
            } else {
                newNums[res++] = nums[i];
                exists = false;
            }
            if (!exists) {
                if (nums[i] == nums[i-1]) {
                    exists = true;
                } else {
                    exists = false;
                }
            }
        }
        nums = newNums;
        return res;
    }

};
