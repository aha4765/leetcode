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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorder_s, int inorder_e, int postorder_s, int postorder_e) {
        if (inorder_s > inorder_e) return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder_e]);
        int i;
        for (i = inorder_s; i <= inorder_e; ++i) {
            if (inorder[i] == postorder[postorder_e]) break;
        }
        int left_inorder_e = i-1;
        int left_node_num = i - inorder_s;
        root->left = buildTreeHelper(inorder, postorder, inorder_s, i-1, postorder_s, postorder_s+left_node_num-1);
        root->right = buildTreeHelper(inorder, postorder, i+1, inorder_e, postorder_s+left_node_num, postorder_e-1);
        return root;
    }
};
