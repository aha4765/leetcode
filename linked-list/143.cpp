// Code should be cleaner

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
    void reorderList(ListNode* head) {
        if (head != nullptr) {
            ListNode* l1, *l2;
            l1 = head; 
            l2 = head;
            while ((l2->next != nullptr) && (l2->next->next != nullptr)) {
                l1 = l1->next;
                l2 = l2->next->next;
            }
            l2 = l1->next;
            l1->next = nullptr;
            
            ListNode* pre = nullptr;
            ListNode* cur = l2;
            ListNode* next;
            while (cur != nullptr) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            
            ListNode* cur1 = head;
            ListNode* next1;
            ListNode* cur2 = pre;
            ListNode* next2;
            while ((cur2 != nullptr) && (cur1 != nullptr)) {
                next1 = cur1->next;
                next2 = cur2->next;
                cur1->next = cur2;
                cur1 = next1;
                cur2->next = next1;
                cur2 = next2;
            }
            if (cur1 != nullptr) cur1->next = nullptr;
        }
    }
};
