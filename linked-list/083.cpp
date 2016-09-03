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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* cur = head;
        ListNode* next = cur->next;
        while (next != nullptr) {
            if (cur->val == next->val) {
                next = next->next;
            }
            else {
                cur->next = next;
                cur = next;
                next = next->next;
            }
        }
        cur->next = nullptr;
        return head;
    }
};
