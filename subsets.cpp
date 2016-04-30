class Solution {

public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        res.reserve(pow(2, size));
        res.push_back({});
        if (size == 0) return res;

        sort(nums.begin(), nums.end());
        for (int num: nums) {
            int curSize = res.size();
            for (int i=0; i<curSize; i++) {
                res.push_back(res[i]);
            }

            for (int i=curSize; i<2*curSize; i++) {
                vector<int>& tmpVec = res[i];
                tmpVec.push_back(num);
            }
        }

        return res;
    }
};
