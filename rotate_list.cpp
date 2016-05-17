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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        
        ListNode *cur = head;
        ListNode* tail = NULL;
        int len = 1;
        while (cur->next) {
            cur = cur->next;
            len ++;
        }
        tail = cur;
        
        k = len - k % len;
        
        cur = head;
        while (--k) {
            cur = cur->next;
        }
        tail->next = head;
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
