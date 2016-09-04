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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tempnode = ListNode(0);
        ListNode* cur = &tempnode;
        
        while ((l1 != nullptr) && (l2 != nullptr)) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr) {
            cur->next = l1;
        }
        else {
            cur->next = l2;
        }
        return tempnode.next;
    }
};
