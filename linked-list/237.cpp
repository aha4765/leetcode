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
    void deleteNode(ListNode* node) {
        ListNode* curnode = node;
        while (curnode->next->next != nullptr) {
            curnode->val = curnode->next->val;
            curnode = curnode->next;
        }
        curnode->val = curnode->next->val;
        curnode->next = nullptr;
    }
};
