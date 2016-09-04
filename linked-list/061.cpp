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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        int len = 0;
        ListNode* cur = head;
        ListNode* tail = nullptr;
        while (cur != nullptr) {
            ++len;
            tail = cur;
            cur = cur->next;
        }
        tail->next = head;
        int shift = len-k%len-1;
        cur = head;
        for (int i = 0; i < shift; ++i) {
            cur = cur->next;
        }
        ListNode* res = cur->next;
        cur->next = nullptr;
        return res;
    }
};
