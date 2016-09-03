// make code cleaner

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* onestep = head;
        ListNode* twostep = head;
        
        while  ((twostep != nullptr) && (twostep->next != nullptr)) {
            onestep = onestep->next;
            twostep = twostep->next->next;
            if (onestep == twostep) break;
        }
        if ((twostep == nullptr) || (twostep->next == nullptr)) return nullptr;
        
        ListNode* l1 = head;
        while (l1 != onestep) {
            l1 = l1->next;
            onestep = onestep->next;
        }
        return l1;
    }
};
