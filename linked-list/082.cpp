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
        
        ListNode* temp = new ListNode(head->val-1);
        temp->next = nullptr;
        ListNode* tail = temp;
        ListNode* pre = temp;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while ((cur != nullptr) && (next != nullptr)) {
            if ((cur->val != pre->val) && (cur->val != next->val)) {
                tail->next = cur;
                tail = cur;
            }
            pre = cur;
            cur = next;
            next = next->next;
        }
        if (cur->val != pre->val) {
            tail->next = cur;
            cur->next = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        ListNode* res = temp->next;
        delete temp;
        return res;
    }
};
