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
    // recursive solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderHelper(root, res);
        return res;
    }
    void preorderHelper(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        res.push_back(node->val);
        preorderHelper(node->left, res);
        preorderHelper(node->right, res);
        return;
    }
};

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
    // iterative solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* tempnode = st.top();
            st.pop();
            res.push_back(tempnode->val);
            if (tempnode->right != nullptr) st.push(tempnode->right);
            if (tempnode->left != nullptr) st.push(tempnode->left);
        }
        return res;
    }
};
