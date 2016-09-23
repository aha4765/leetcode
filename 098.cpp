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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        else if ((root->left == nullptr) && (root->right == nullptr)) return true;
        else if (!isValidBST(root->left) || !isValidBST(root->right)) return false;
        else if ((root->left != nullptr) && (findmax(root->left) >= root->val)) return false;
        else if ((root->right != nullptr) && (findmin(root->right) <= root->val)) return false;
        return true;
    }
    
    int findmax(TreeNode* root) {
        if (root->right == nullptr) return root->val;
        else {
            return findmax(root->right);
        }
    }
    int findmin(TreeNode* root) {
        if (root->left == nullptr) return root->val;
        else {
            return findmin(root->left);
        }
    }
};
