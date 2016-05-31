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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 0 || head == NULL) return head;
        
        int length = 0;
        ListNode* node = head;
        while (node) {
            node = node->next;
            length ++;
        }
        if (length < k) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        node = head;
        for (int i = 0; i < (length / k); i++) {
            tail = node;
            for (int j = 0; j < k; j++) {
                ListNode* next = node->next;
                node->next = dummy->next;
                dummy->next = node;
                node = next;
            }
            if (newHead == NULL) {
                newHead = dummy->next;
            }
            tail->next = node;
            dummy = tail;
            
        }
        
        if (node) {
            tail->next = node;
        } else {
            tail->next = NULL;
        }
        
        return newHead;
    }
};
