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
    bool traverse(TreeNode* root, stack<TreeNode*>& s, vector<int>& res) {
        if (root == NULL) return true;
        
        while (root->left) {
            s.push(root);
            res.push_back(root->val);
            root = root->left;
        }
        s.push(root);
        res.push_back(root->val);
        
        // if root has right, then the node is middle
        if (root->right) {
            return true;
        } else {
            return false;
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        stack<TreeNode*> s;
        bool isMiddle = traverse(root, s, res);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            
            if (isMiddle) {
                node = node->right;
                isMiddle = traverse(node, s, res);
            } else {
                isMiddle = true;
            }
        }
        
        return res;
    }
};
