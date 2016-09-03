/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* prenode = head;
        ListNode* onestep = head;
        ListNode* twostep = head;
        while ((twostep->next != nullptr) && (twostep->next->next != nullptr)) {
            prenode = onestep;
            onestep = onestep->next;
            twostep = twostep->next->next;
        }
        TreeNode* temp = new TreeNode(onestep->val);
        if (onestep == head) {
            temp->left = nullptr;
        }
        else {
            prenode->next = nullptr;
            temp->left = sortedListToBST(head);
        }
        if (onestep->next == nullptr) {
            temp->right = nullptr;
        }
        else {
            temp->right = sortedListToBST(onestep->next);
        }
        return temp;
    }
};
