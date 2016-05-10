/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find the middle
        ListNode* cur = head;
        ListNode* next = head;
        
        while (next && next->next) {
            cur = cur->next;
            next = next->next->next;
        }
        
        if (next) cur = cur->next;
        
        // reverse the right list
        cur = reverse(cur);
        next = head;
        while (next < cur) {
            if (next->val != cur->val) return false;
            cur = cur->next;
            next = next->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* root) {
        if (root == NULL) return root;
        
        ListNode *pre = NULL;
        ListNode *cur = root;
        
        while (cur->next) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur->next = pre;
        
        return cur;
    } 
};
