class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        if (k <= 0) {
            return res;
        }
        combination(1, k, n);
        
        return res;
    }
    
private:
    vector<vector<int> > res;
    vector<int> path;
    
    void combination(int start, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(path);
            return;
        }
        
        // pruning;
        if (k * start + k*(k-1)/2 > n) {
            return;
        }
        
        for (int i=start; i<=min(n,9); i++) {
            path.push_back(i);
            combination(i+1, k-1, n-i);
            path.pop_back();
        }
    }
};

