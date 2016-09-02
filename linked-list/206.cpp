// remembe, we can reverse a linked list, when we are allowed

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* next = head->next;
        ListNode* pre = nullptr;
        while (head != nullptr) {
            head->next = pre;
            if (next == nullptr) {
                break;
            }
            pre = head;
            head = next;
            next = head->next;
        }
        return head;
    }
};
