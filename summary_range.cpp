class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int size = nums.size();
        if (size == 0) return res;
        
        int ind = 0;
        while (ind < size) {
            int start = nums[ind];
            int cur = nums[ind];
            while (ind + 1 < size && cur + 1 == nums[ind+1]) {
                ind ++;
                cur = nums[ind];
            }
            if (cur != start) {
                res.push_back(to_string(start) + "->" + to_string(cur));
            } else {
                res.push_back(to_string(start));
            }
            ind ++;
        }
        return res;
    }
};
