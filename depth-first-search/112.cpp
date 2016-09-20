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
    bool hasPathSum(TreeNode* root, int sum) {
        return find_path(root, sum);
    }
    
    bool find_path(TreeNode* node, int expect) {
        if (node == nullptr) return false;
        if ((node->left == nullptr) && (node->right == nullptr)) {
            if (node->val == expect) {
                return true;
            }
            else {
                return false;
            }
        }
        if (find_path(node->left, expect - node->val)) return true;
        if (find_path(node->right, expect - node->val)) return true;
        return false;
    }
};
