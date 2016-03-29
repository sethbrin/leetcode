class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return;
        }
        
        int ind = 0;
        while (ind < size-1) {
            if (ind < size -1 && nums[ind] >= nums[ind+1]) {
                // in the later number find a bigger one, then swap with ind+1
                int k = ind+2;
                // As all input has valid answer
                while (k < size && nums[ind]>=nums[k]) {
                    k ++;
                }
                swap(nums[ind+1], nums[k]);
            }
           
            ind ++;
            if (ind < size -1 && nums[ind] <= nums[ind+1]) {
                // in the later number find a smaller one, then swap with ind+1
                int k = ind+2;
                // As all input has valid answer
                while (k < size && nums[ind]<=nums[k]) {
                    k ++;
                }
                swap(nums[ind+1], nums[k]);
            }
            ind ++;
        }
    }
};

