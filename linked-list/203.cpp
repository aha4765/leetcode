/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 *           while ((next->val == val) && (next != nullptr)) {
 *              next = next->next;
 *           }
 *  will have runtime error!!
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        while (head != nullptr) {
            if (head->val != val) break;
            head = head->next;
        }
        ListNode* cur = head;
        ListNode* next;
        if (cur != nullptr) {
            next = cur->next;
        }
        while ((cur != nullptr) && (next != nullptr)) {
            while (next->val == val) {
                next = next->next;
                if (next == nullptr) break;
            }
            cur->next = next;
            cur = next;
            if (next != nullptr) {
                next = next->next;
            }
        }
        return head;
    }
};
