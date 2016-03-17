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
        
        // store the first index of the list
        // if item with index i is duplicate, we set m[i] = -1
        // later we will remove it from the list
        unordered_map<int, int> m;
        ListNode *cur = head, *pre;
        int ind = 0;
        while (cur != NULL) {
            if (m.find(cur->val) != m.end()) {
                m[cur->val] = -1;
                // remove the current node
                pre->next = cur->next;
            } else {
                m[cur->val] = ind;
                ind ++;
                pre = cur;
            }
            cur = cur->next;
        }
        
        // remove the node with m[ind] = -1
        cur = head;
        pre = preHead;
        ind = 0;
        
        while (cur != NULL) {
            if (-1 == m[cur->val]) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        
        return preHead->next;
    }
};
