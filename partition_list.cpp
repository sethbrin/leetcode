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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        
        ListNode *left = dummy1;
        ListNode *right = dummy2;
        
        while (head) {
            if (head->val < x) {
                dummy1->next = head;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = head;
                dummy2 = dummy2->next;
            }
            
            head = head->next;
        }
        
        dummy2->next = NULL;
        dummy1->next = right->next;
        
        return left->next;
    }
};
