/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // first add the copy node to the list
        // value the random area
        // restore list and the copy list
        if (head == NULL) return head;
        
        RandomListNode* iter = head;
        RandomListNode* next;
        
        while (iter != NULL) {
            next = iter->next;
            RandomListNode* copy = new RandomListNode(iter->label);
            iter->next = copy;
            copy->next = next;
            
            iter = next;
        }
        
        iter = head;
        while (iter != NULL) {
            next = iter->next->next;
            if (iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = next;
        }
        
        RandomListNode* copyPreHead = new RandomListNode(0);
        RandomListNode* copy;
        RandomListNode* copyPre = copyPreHead;
        iter = head;
        while (iter != NULL) {
            next = iter->next->next;

            // copy list
            copy = iter->next;
            copyPre->next = copy;
            copyPre = copy;
            
            // restore origin list
            iter->next = next;
            
            iter = next;
        }
        
        RandomListNode* copyHead = copyPreHead->next;
        delete copyPreHead;
        return copyHead;
    }
};
