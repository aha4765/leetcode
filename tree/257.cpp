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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        stringstream ss;
        ss << root->val;
        if ((root->left == nullptr) && (root->right == nullptr)) {
            string cur = ss.str();
            res.push_back(cur);
        }
        
        if (root->left != nullptr) {
            for (auto tempstr : binaryTreePaths(root->left)) {
                string cur = ss.str() + "->";
                cur.append(tempstr);
                res.push_back(cur);
            }
        }
        if (root->right != nullptr) {
            for (auto tempstr : binaryTreePaths(root->right)) {
                string cur = ss.str() + "->";
                cur.append(tempstr);
                res.push_back(cur);
            }
        }
        return res;
    }
};
