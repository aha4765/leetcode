// This solution includes redundant computation
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftdepth = tree_depth(root->left);
        int rightdepth = tree_depth(root->right);
        
        if ((leftdepth < (rightdepth - 1)) || (leftdepth > (rightdepth + 1))) {
            return false;
        }
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        return true;
    }
    
    int tree_depth(TreeNode* node) {
        if (node == nullptr) return 0;
        int res0 = tree_depth(node->left);
        int res1 = tree_depth(node->right);
        if (res0 == 0) {
            return res1 + 1;
        }
        if (res1 == 0) {
            return res0 + 1;
        }
        return max(res0, res1) + 1;
    }
};

// avoid redundant computation by introducing -1 as tree height for imbalanced tree
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftdepth = tree_depth(root->left);
        if (leftdepth == -1) return false;
        int rightdepth = tree_depth(root->right);
        if (rightdepth == -1) return false;
        
        if ((leftdepth < (rightdepth - 1)) || (leftdepth > (rightdepth + 1))) {
            return false;
        }
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        return true;
    }
    
    int tree_depth(TreeNode* node) {
        if (node == nullptr) return 0;
        int res0 = tree_depth(node->left);
        if (res0 == -1) return -1;
        int res1 = tree_depth(node->right);
        if (res1 == -1) return -1;
        if ((res0 < (res1 - 1)) || (res0 > (res1 + 1))) {
            return -1;
        }
        if (res0 == 0) {
            return res1 + 1;
        }
        if (res1 == 0) {
            return res0 + 1;
        }
        return max(res0, res1) + 1;
    }
};
