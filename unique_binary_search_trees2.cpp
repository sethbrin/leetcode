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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        vector<TreeNode*> leftNodes;
        vector<TreeNode*> rightNodes;
        
        for (int i=start; i<=end; i++) {
            leftNodes = generateTrees(start, i-1);
            rightNodes = generateTrees(i+1, end);
            
            for (TreeNode* left: leftNodes) {
                for (TreeNode* right: rightNodes) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};
