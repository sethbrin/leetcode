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
    bool isValidBST(TreeNode* root, long maxVal, long minVal) {
        if (root == NULL) return true;
        
        return (root->left == NULL || 
                   (root->val > root->left->val
                    && root->left->val > minVal
                    && isValidBST(root->left, root->val, minVal)
                   )
               ) &&
               (root->right == NULL ||
                   (root->val < root->right->val
                    && root->right->val < maxVal
                    && isValidBST(root->right, maxVal, root->val)
                    )
                );
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
};
