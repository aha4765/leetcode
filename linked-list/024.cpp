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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode temp = ListNode(0);
        ListNode* helper = &temp;
        
        helper->next = head;
        ListNode* cur = head;
        ListNode* pre = helper;
        while ((cur != nullptr) && (cur->next != nullptr)) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = cur->next;
        }
        return helper->next;
    }
};
