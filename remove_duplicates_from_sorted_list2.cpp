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
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head || NULL == head->next){
            return head;
        }
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        
        // Note: the list is sorted
        ListNode* pre = preHead;
        ListNode* cur = head;
        
        bool isDuplicate = false;
        while (cur != NULL) {
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            
            cur = cur->next;
            isDuplicate = false;
        }
        
        return preHead->next;
    }
};
