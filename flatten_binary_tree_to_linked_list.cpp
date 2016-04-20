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
    TreeNode* flatten2(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left != NULL) {
            root->left = NULL;
            root->right = left;
            root = flatten2(left);
        }
        if (right != NULL) {
            root->left = NULL;
            root->right = right;
            root = flatten2(right);
        }
        return root;
    }
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        flatten2(root);
    }
};
