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
private:
    bool isBalanced(TreeNode* root, int& height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int leftHeight;
        bool balance = isBalanced(root->left, leftHeight);
        if (!balance) {
            return false;
        }

        int rightHeight;
        balance = isBalanced(root->right, rightHeight);
        if (!balance) {
            return false;
        }

        height = max(leftHeight, rightHeight) + 1;
        if (abs(leftHeight - rightHeight) <= 1) {
            return true;
        } else {
            return false;
        }
    }

public:

    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced(root, height);
    }

};
