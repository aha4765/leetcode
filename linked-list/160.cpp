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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ((headA == nullptr) || (headB == nullptr)) return nullptr;
        ListNode* ptrA;
        ListNode* ptrB;
        int stepA = 0, stepB = 0;
        ptrA = headA;
        ptrB = headB;
        while (ptrA->next != nullptr) {
            ++stepA;
            ptrA = ptrA->next;
        }
        while (ptrB->next != nullptr) {
            ++stepB;
            ptrB = ptrB->next;
        }
        if (ptrA != ptrB) {
            return nullptr;
        }
        ptrA = headA;
        ptrB = headB;
        if (stepA > stepB) {
            for (int i = 0; i < (stepA-stepB); ++i) {
                ptrA = ptrA->next;
            }
        }
        else if (stepA < stepB) {
            for (int i = 0; i < (stepB-stepA); ++i) {
                ptrB = ptrB->next;
            }
        }
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};
