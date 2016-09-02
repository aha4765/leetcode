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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)  return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddcur = head;
        ListNode* evencur = head->next;
        while ((oddcur != nullptr) && (evencur != nullptr)) {
            if ((evencur->next == nullptr) || (evencur == nullptr)) {
                break;
            }
            oddcur->next = oddcur->next->next;
            evencur->next = evencur->next->next;
            oddcur = oddcur->next;
            evencur = evencur->next;
        }
        oddcur->next = even;
        return odd;
    }
};
