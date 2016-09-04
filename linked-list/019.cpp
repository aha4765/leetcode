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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        if (n == 0) return head;
        ListNode temp = ListNode(0);
        temp.next = head;
        ListNode* cur = head;
        ListNode* pre = &temp;
        ListNode* next = head;
        for (int i = 0; i < n; ++i) {
            next = next->next;
        }
        while (next != nullptr) {
            pre = cur;
            cur = cur->next;
            next = next->next;
        }
        pre->next = cur->next;
        return temp.next;
    }
};
