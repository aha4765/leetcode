// code should be cleaner

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) return nullptr;
        ListNode* prestart;
        ListNode* postend;
        ListNode* start;
        ListNode* end;
        prestart = nullptr;
        start = head;
        end = head;
        postend = head->next;
        for (int i = 1; i < m; ++i) {
            prestart = start;
            start = start->next;
            end = end->next;
            postend = end->next;
        }
        for (int i = m; i < n; ++i) {
            end = end->next;
            postend = end->next;
        }
        // now reverse the list from start to end
        if (start == nullptr) return head;
        end->next = nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = start;
        ListNode* next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (prestart == nullptr) {
            start->next = postend;
            return end;
        }
        else {
            prestart->next = end;
            start->next = postend;
            return head;
        }
    }
};
