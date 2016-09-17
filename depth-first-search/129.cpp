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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) return sum;
        dfs(root, 0, sum);
        return sum;
    }
    
    int dfs(TreeNode* node, int pre, int& sum) {
        if (node->left != nullptr) {
            dfs(node->left, 10*pre+node->val, sum);
        }
        if (node->right != nullptr) {
            dfs(node->right, 10*pre+node->val, sum);
        }
        if ((node->left == nullptr) && (node->right == nullptr)) {
            sum += (10*pre+node->val);
        }
        return 0;
    }
};
