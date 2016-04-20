#include <iostream>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;
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
            root->right = left;
            root = flatten2(left);
        }
        if (right != NULL) {
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

int main()
{
  Solution s;
  TreeNode* root = new TreeNode(3);
  TreeNode* left = new TreeNode(1);

  root->left = left;

  s.flatten(root);
  return 0;
}
