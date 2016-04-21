/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void pathSum2(TreeNode* root, int sum, vector<int> curVec, vector<vector<int>>& res) {
        if (root == NULL) return;
        
        curVec.push_back(root->val);
        sum -= root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) {
                res.push_back(curVec);
            }
            return;
        }
        
        pathSum2(root->left, sum, curVec, res);
        pathSum2(root->right, sum, curVec, res);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        
        pathSum2(root, sum, vector<int>(), res);
        
        return res;
    }
};
