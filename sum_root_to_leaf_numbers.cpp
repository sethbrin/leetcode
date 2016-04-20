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
    int traverseLeaf(TreeNode* root, int val) {
        if (root == NULL) return 0;
        
        val = val * 10 + root->val;
        
        if (root->left == NULL && root->right == NULL) {
            return val;
        }
        
        return traverseLeaf(root->left, val) + traverseLeaf(root->right, val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return traverseLeaf(root, 0);
    }
};
