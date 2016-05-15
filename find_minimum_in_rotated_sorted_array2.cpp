class Solution {
public:
    int findMin(vector<int>& nums) {
        // binary search
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else if(nums[mid] == nums[end]) {
                end --;
            } else {
                end = mid;
            }
            
        }
        return nums[start];
    }
};
