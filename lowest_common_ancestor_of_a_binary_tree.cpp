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
    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (root == NULL) return false;
        path.push_back(root);
        if (root == node) return true;
        
        if (getPath(root->left, node, path) || getPath(root->right, node, path)) {
            return true;
        } else {
            path.pop_back();
            return false;
        }
        
    } 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        
        vector<TreeNode*> pPath, qPath;
        getPath(root, p, pPath);
        getPath(root, q, qPath);
        
        pair<vector<TreeNode*>::iterator, vector<TreeNode*>::iterator> res;
        if (pPath.size() < qPath.size()) {
            res = mismatch(pPath.begin(), pPath.end(), qPath.begin());
        } else {
            res = mismatch(qPath.begin(), qPath.end(), pPath.begin());
        }
        return *(--res.first);
    }
};
