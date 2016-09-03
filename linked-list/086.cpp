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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode* cur = head;
        
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* smallhead = small;
        ListNode* bighead = big;
        
        while (cur != nullptr) {
            if (cur->val < x) {
                smallhead->next = cur;
                smallhead = smallhead->next;
            }
            else {
                bighead->next = cur;
                bighead = bighead->next;
            }
            cur = cur->next;
        }
        // break the loop
        bighead->next = nullptr;
        smallhead->next = nullptr;
        if (smallhead == small) return head;
        if (bighead == big) return head;
        smallhead->next = big->next;
        return small->next;
    }
};
