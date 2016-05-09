class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // the number n should be in (n-1)postion
        
        int size = nums.size();
        
        for (int i=0; i<size; i++) {
            int cur = nums[i];
            // skip when the cur number in the right place 
            if (cur == i+1 || cur <= 0 || cur > size) {
                continue;
            }
            
            swap(nums[i], nums[cur-1]);
            
            // reprocess the number nums[i] as it is changed to nums[cur-1]
            if (nums[i] != nums[cur-1]) {
                i --;
            }
        }
        // now all the number start from index 0 is ordered
        for (int i=0; i<size; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return size+1;
    }
};
