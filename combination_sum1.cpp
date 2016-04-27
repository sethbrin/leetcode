class Solution {

private:

    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target, int index) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i=index; i<candidates.size(); i++) {
            int num = candidates[i];
            if (target < num) break;

            path.push_back(num);
            dfs(res, path, candidates, target - num, i);
            path.pop_back();
        }
    }

public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;

        dfs(res, path, candidates, target, 0);
        return res;
    }
};
