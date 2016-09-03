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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        
        ListNode* onestep = head;
        ListNode* twostep = head;
        while ((twostep != nullptr) && (twostep->next != nullptr)) {
            onestep = onestep->next;
            twostep = twostep->next->next;
            if (onestep == twostep) {
                return true;
            }
        }
        return false;
    }
};
