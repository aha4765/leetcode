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
    // recursive
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
    
    void inorderHelper(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        inorderHelper(node->left, res);
        res.push_back(node->val);
        inorderHelper(node->right, res);
        return;
    }
};
