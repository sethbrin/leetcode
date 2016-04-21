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
    // [start, end)
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start == end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};
