class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res = {{}};
        int size = nums.size();
        for (int i=0; i<size;) {
            int cnt = 0; // repeat count
            
            while (i + cnt < size && nums[i+cnt] == nums[i]) {
                cnt ++;
            }
            
            int curSetSize = res.size();
            for (int j=0; j<curSetSize; j++) {
                vector<int> instance = res[j];
                for (int k=0; k<cnt; k++) {
                    instance.push_back(nums[i]);
                    res.push_back(instance);
                }
            }
            
            i += cnt;
        }
        
        return res;
    }
};
