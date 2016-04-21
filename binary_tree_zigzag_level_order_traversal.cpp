// use the method like traverse level 102. Binary Tree Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        
        vector<int> tmp;
        tmp.push_back(root->val);
        res.push_back(tmp);
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = false; // if true start from left
        
        int count = 1;
        TreeNode* tmpNode;
        while (!q.empty()) {
            int curCount = 0;
            deque<int> levelNum;
            while (count--) {
                tmpNode = q.front();
                q.pop();
                
                // push the node
                if (tmpNode->left != NULL) {
                    q.push(tmpNode->left);
                    
                    curCount ++;
                    if (flag) {
                        levelNum.push_back(tmpNode->left->val);
                    } else {
                        levelNum.push_front(tmpNode->left->val);
                    }
                }
                if (tmpNode->right != NULL) {
                    q.push(tmpNode->right);
                    
                    curCount ++;
                    if (flag) {
                        levelNum.push_back(tmpNode->right->val);
                    } else {
                        levelNum.push_front(tmpNode->right->val);
                    }
                }
            }
            if (curCount > 0) {
                count = curCount;
                res.push_back(vector<int>(levelNum.begin(), levelNum.end()));
            }
            flag = !flag;
        }
        return res;
    }
};
