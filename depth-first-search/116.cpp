/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        root->next = nullptr;
        TreeLinkNode* up = root;
        TreeLinkNode* curup = up;
        TreeLinkNode temp = TreeLinkNode(-1);
        while (up != nullptr) {
            curup = up;
            TreeLinkNode* curlow = &temp;
            while (curup != nullptr) {
                curlow->next = curup->left;
                if (curup->left == nullptr) return;
                curlow = curlow->next;
                curlow->next = curup->right;
                curlow = curlow->next;
                curup = curup->next;
            }
            curlow->next = nullptr;
            up = up->left;
        }
    }
};
