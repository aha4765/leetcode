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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (isleaf(root->left)) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    inline bool isleaf(TreeNode* node) {
        if (node == nullptr) return false;
        if ((node->left == nullptr) && (node->right == nullptr)) return true;
        return false;
    }
};
