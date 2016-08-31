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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* cur = new ListNode(-1);
        ListNode* res = cur;
        
        int inc = 0;
        int add1 = 0;
        int add2 = 0;
        while ((l1 != nullptr) || (l2 != nullptr) || (inc != 0)) {
            if (l1 == nullptr) {
                add1 = 0;
            }
            else {
                add1 = l1->val;
                l1 = l1->next;
            }
            if (l2 == nullptr) {
                add2 = 0;
            }
            else {
                add2 = l2->val;
                l2 = l2->next;
            }
            int sum;
            if ((add1 + add2 + inc) >= 10) {
                sum = add1 + add2 + inc - 10;
                inc = 1;
            }
            else {
                sum = add1 + add2 + inc;
                inc = 0;
            }
            ListNode* temp = new ListNode(sum);
            cur->next = temp;
            cur = temp;
        }
        return res->next;
    }
};
