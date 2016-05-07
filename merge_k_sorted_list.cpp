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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        int mid = (start + end) / 2;
        
        ListNode* left = mergeKLists(lists, start, mid);
        ListNode* right = mergeKLists(lists, mid+1, end);
        
        return mergeTwoLists(left, right);
    }
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while (left && right) {
            if (left->val < right->val) {
                dummy->next = left;
                left = left->next;
            } else {
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        if (left) {
            dummy->next = left;
        }
        if (right) {
            dummy->next = right;
        }
        
        return head->next;
    }
};
