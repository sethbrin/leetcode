class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the first reverse order
        int size = nums.size();
        
        if (size < 1) {
            return;
        }
        for (int i=size-2; i>=0; i--) {
            for (int j=size-1; j>i; j--) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
