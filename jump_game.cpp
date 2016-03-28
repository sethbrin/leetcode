class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (1 == size || 0 == size) {
            return true;
        }
        vector<int> canReach(size, false);
        canReach[0] = true;
        int lastInd = 0;
        for (int i=0; i<size-1; i++) {
            if (i > lastInd && !canReach[i]) {
                return false;
            }
            int ind = i + nums[i];
            bool flag = canReach[i] && true;
            if (ind >= size-1) {
                return true;
            } else {
                canReach[ind] = flag;
            }
            lastInd = max(ind, lastInd);
        }
        
        return canReach[size-2] && nums[size-2]>0;
    }
};

