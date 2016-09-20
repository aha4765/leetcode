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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return find_depth(root, 0);
    }
    
    // first dfs
    // this function returns the min depth of the leaves under node, depth is the current depth of the node's parent
    int find_depth(TreeNode* node, int depth) {
        int res0 = INT_MAX;
        int res1 = INT_MAX;
        if ((node->left == nullptr) && (node->right == nullptr)) {
            return depth + 1;
        }
        if (node->left != nullptr) {
            res0 = find_depth(node->left, depth+1);
        }
        if (node->right != nullptr) {
            res1 = find_depth(node->right, depth+1);
        }
        return min(res0, res1);
    }
};
