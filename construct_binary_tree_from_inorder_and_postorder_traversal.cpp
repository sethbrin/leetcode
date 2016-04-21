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
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int& curSplit, 
        IntIterator start, IntIterator end) {
            
        if (start == end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[curSplit]);
        IntIterator pos = find(start, end, postorder[curSplit]);
        
        --curSplit;
        root->right = buildTree(postorder, inorder, curSplit, pos+1, end);
        root->left = buildTree(postorder, inorder, curSplit, start, pos);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int curSplit = inorder.size() - 1;
        return buildTree(postorder, inorder, curSplit, inorder.begin(), inorder.end());
    }
};
