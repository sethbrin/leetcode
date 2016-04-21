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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        
        vector<int> tmp;
        tmp.push_back(root->val);
        res.push_back(tmp);
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        int count = 1;
        while (!q.empty()) {
            int curCount = 0;
            vector<int> levelNum;
            while (count--) {
                TreeNode* tmp = q.front();
                q.pop();
                // push the node
                if (tmp->left != NULL) {
                    q.push(tmp->left);
                    curCount ++;
                    levelNum.push_back(tmp->left->val);
                }
                if (tmp->right != NULL) {
                    q.push(tmp->right);
                    curCount ++;
                    levelNum.push_back(tmp->right->val);
                }
            }
            if (curCount > 0) {
                count = curCount;
                res.push_back(levelNum);
            }
        }
        return res;
    }
};
