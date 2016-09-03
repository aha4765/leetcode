// code is too verbose, should be cleaner

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* pre = temp;
        ListNode* cur = head;
        ListNode* sortnode = head->next;
        ListNode* lastsort = head;
        while (sortnode != nullptr) {
            pre = temp;
            cur = temp->next;
            while (cur != sortnode) {
                if (sortnode->val > cur->val) {
                    pre = cur;
                    cur = cur->next;
                }
                else {
                    pre->next = sortnode;
                    sortnode = sortnode->next;
                    pre->next->next = cur;
                    lastsort->next = sortnode;
                    break;
                }
            }
            if (cur == sortnode) {
                sortnode = sortnode->next;
                lastsort = lastsort->next;
            }
        }
        ListNode* res = temp->next;
        delete temp;
        return res;
    }
};
