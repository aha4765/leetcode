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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
        int preorder_s, int preorder_e, int inorder_s, int inorder_e) {
        if (preorder_s > preorder_e) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_s]);
        int i;
        for (i = inorder_s; i <= inorder_e; ++i) {
            if (inorder[i] == preorder[preorder_s]) {
                break;
            }
        }
        int leftnum = i-inorder_s;
        int left_pre_s = preorder_s + 1;
        int left_pre_e = preorder_s + leftnum;
        int left_in_s = inorder_s;
        int left_in_e = i-1;
        int right_pre_s = preorder_s + leftnum + 1;
        int right_pre_e = preorder_e;
        int right_in_s = i+1;
        int right_in_e = inorder_e;
        root->left = buildTreeHelper(preorder, inorder, left_pre_s, left_pre_e, left_in_s, left_in_e);
        root->right = buildTreeHelper(preorder, inorder, right_pre_s, right_pre_e, right_in_s, right_in_e);
        return root;
    }
};
