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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        stack<TreeNode*> treest0, treest1;
        stack<TreeNode*>* st0 = &treest0;
        stack<TreeNode*>* st1 = &treest1;
        st0->push(root);
        bool left = true;
        while (!st0->empty()) {
            vector<int> tempvector;
            while (!st0->empty()) {
                TreeNode* tempnode = st0->top();
                st0->pop();
                tempvector.push_back(tempnode->val);
                if (left) {
                    if (tempnode->left != nullptr) st1->push(tempnode->left);
                    if (tempnode->right != nullptr) st1->push(tempnode->right);
                }
                else {
                    if (tempnode->right != nullptr) st1->push(tempnode->right);
                    if (tempnode->left != nullptr) st1->push(tempnode->left);
                }
            }
            left = !left;
            res.push_back(tempvector);
            swap(st0, st1);
        }
        return res;
    }
};
