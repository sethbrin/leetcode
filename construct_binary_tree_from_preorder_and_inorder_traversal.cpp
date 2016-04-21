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
    typedef vector<int>::iterator IntIterator;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& curSplit, 
        IntIterator start, IntIterator end) {
            
        if (start == end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[curSplit]);
        IntIterator pos = find(start, end, preorder[curSplit]);
        
        ++curSplit;
        root->left = buildTree(preorder, inorder, curSplit, start, pos);
        root->right = buildTree(preorder, inorder, curSplit, pos+1, end);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int curSplit = 0;
        return buildTree(preorder, inorder, curSplit, inorder.begin(), inorder.end());
    }
};
