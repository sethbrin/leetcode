/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int count(ListNode* head) {
        int size = 0;
        while (head) {
            head = head->next;
            size ++;
        }
        return size;
    }
    
    TreeNode* sortedListToBST(int n, ListNode*& cur) {
        if (n == 0) {
            return NULL;
        }
        TreeNode* node = new TreeNode(0);
        node->left = sortedListToBST(n/2, cur);
        node->val = cur->val;
        cur = cur->next;
        node->right = sortedListToBST(n - n/2 - 1, cur);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // inorder traverse
        
        return sortedListToBST(count(head), head);
    }
};
