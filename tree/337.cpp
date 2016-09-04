// From discussion, new approach
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

    struct Tuple {
        int noroot;
        int withroot;
        Tuple() {noroot = 0; withroot = 0;}
        int val() {
            return max(noroot, withroot);
        }
    };
    
    int rob(TreeNode* root) {
        Tuple res = helper(root);
        return res.val();
    }
    
    Tuple helper(TreeNode* root) {
        if (root == nullptr) return Tuple();
        int robroot = 0;
        robroot += root->val;
        Tuple left = helper(root->left);
        Tuple right = helper(root->right);
        robroot += left.noroot;
        robroot += right.noroot;
        
        int noroot = 0;
        noroot += left.withroot;
        noroot += right.withroot;
        
        Tuple res;
        res.noroot = noroot;
        res.withroot = max(robroot, noroot);
        
        return res;
    }
};

// time exceed limit
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> table;
        return helper(root, table);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int> table) {
        if (root == nullptr) return 0;
        if (table.find(root) != table.end()) return table[root];
        int robroot = 0;
        robroot += root->val;
        if (root->left != nullptr) {
            robroot += helper(root->left->left, table);
            robroot += helper(root->left->right, table);
        }
        if (root->right != nullptr) {
            robroot += helper(root->right->left, table);
            robroot += helper(root->right->right, table);
        }
        int noroot = 0;
        noroot = helper(root->left, table) + helper(root->right, table);
        table[root] = max(robroot, noroot);
        return max(robroot, noroot);
    }
};
