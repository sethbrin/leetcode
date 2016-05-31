class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // keep removing the leafs until the node count is 1 or 2
        vector<unordered_set<int>> adj(n, unordered_set<int>());
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        
        // set adj
        for (auto item : edges) {
            adj[item.first].insert(item.second);
            adj[item.second].insert(item.first);
        }
        
        // find the leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        
        while (n > 2) {
            vector<int> newLeaves;
            for (int leaf : leaves) {
                for (int neighbor : adj[leaf]) {
                    adj[neighbor].erase(leaf);
                    if (adj[neighbor].size() == 1) {
                        newLeaves.push_back(neighbor);
                    }
                }
            }
            
            n -= leaves.size();
            leaves = newLeaves;
        }
        
        return leaves;
    }
};
