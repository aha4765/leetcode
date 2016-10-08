// Get from discussion

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
    int countNodes(TreeNode* root) {
        int lh = 0;
        TreeNode* temp = root;
        while (temp != nullptr) {
            ++lh;
            temp = temp->left;
        }
        int rh = 0;
        temp = root;
        while (temp != nullptr) {
            ++rh;
            temp = temp->right;
        }
        
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
