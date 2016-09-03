// be careful about the pointer and value of pointer

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
    // use merge sort
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode* l1 = head;
        ListNode* l2 = head;
        while ((l2->next != nullptr) && (l2->next->next != nullptr)) {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        l2 = l1->next;
        l1->next = nullptr;
        ListNode* q1 = sortList(head); // I thought that head will be changed to the head of new sorted list, but not!!!
        ListNode* q2 = sortList(l2);
        return merge(q1, q2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* pre = temp;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while ((cur1 != nullptr) && (cur2 != nullptr)) {
            if (cur1->val < cur2->val) {
                pre->next = cur1;
                pre = cur1;
                cur1 = cur1->next;
            }
            else {
                pre->next = cur2;
                pre = cur2;
                cur2 = cur2->next;
            }
        }
        if (cur1 != nullptr) {
            pre->next = cur1;
        }
        if (cur2 != nullptr) {
            pre->next = cur2;
        }
        ListNode* res = temp->next;
        delete temp;
        return res;
    }
};
