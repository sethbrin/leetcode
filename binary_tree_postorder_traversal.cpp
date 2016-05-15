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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
       
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        
        while (root->left) {
            s.push({root->left, false});
            root = root->left;
        }
        while (!s.empty()) {
            auto& top = s.top();
            if (top.second) {
                res.push_back(top.first->val);
                s.pop();
            } else {
                top.second = true;
                TreeNode* node = top.first->right;
                if (node) {
                    s.push({node, false});
                    while (node->left) {
                        s.push({node->left, false});
                        node = node->left;
                    }
                }
            }
        }
        
        return res;
    }
};
