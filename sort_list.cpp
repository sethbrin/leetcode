/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        
        while (head1 && head2) {
            if (head1->val < head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if (head1) {
            p->next = head1;
        }
        if (head2) {
            p->next = head2;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(head2));
    }
};
