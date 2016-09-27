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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<TreeNode*> buffer0, buffer1;
        vector<TreeNode*>* b0 = &buffer0;
        vector<TreeNode*>* b1 = &buffer1;
        b0->push_back(root);
        while (!b0->empty()) {
            vector<int> tempvec;
            for (auto tempnode : *b0) {
                tempvec.push_back(tempnode->val);
                if (tempnode->left != nullptr) {
                    b1->push_back(tempnode->left);
                }
                if (tempnode->right != nullptr) {
                    b1->push_back(tempnode->right);
                }
            }
            res.push_back(tempvec);
            b0->clear();
            swap(b0, b1);
        }
        return res;
    }
};
