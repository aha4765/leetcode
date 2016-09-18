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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    
    TreeNode* dfs(TreeNode* node) {
        if (node == nullptr) return nullptr;
        if ((node->left == nullptr) && (node->right == nullptr)) {
            return node;
        }
        if ((node->left != nullptr) && (node->right == nullptr)) {
            TreeNode* tail = dfs(node->left);
            tail->right = nullptr;
            node->right = node->left;
            node->left = nullptr;
            return tail;
        }
        if ((node->left == nullptr) && (node->right != nullptr)) {
            TreeNode* tail = dfs(node->right);
            tail->right = nullptr;
            return tail;
        }
        if ((node->left != nullptr) && (node->right != nullptr)) {
            TreeNode* tail = dfs(node->left);
            tail->right = node->right;
            tail = dfs(node->right);
            tail->right = nullptr;
            node->right = node->left;
            node->left = nullptr;
            return tail;
        }
        return nullptr;
    }
};
