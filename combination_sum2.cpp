class Solution {
public:
    void combination(vector<int>& candidates, int ind, int sum) {
        if (0 == sum) {
            res.push_back(path);
        }
        
        for (int i=ind; i<candidates.size(); i++) {
            if (sum - candidates[i] < 0) {
                return;
            }
            // As if candidate[i] == candidates[i-1], the following will
            // duplicate 
            if (i != 0 && candidates[i] == candidates[i-1] && ind < i) {
                continue;
            }
            path.push_back(candidates[i]);
            combination(candidates, i+1, sum-candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combination(candidates, 0, target);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};
