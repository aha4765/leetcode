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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> rp, rq;
        
        findRoute(root, p, rp);
        findRoute(root, q, rq);
        TreeNode* common = root;
        int size = min(rp.size(), rq.size());
        for (int i = 0; i < size; ++i) {
            if (rp[i] == rq[i]) {
                common = rp[i];
            }
            else {
                break;
            }
        }
        return common;
    }
    
    bool findRoute(TreeNode* start, TreeNode* end, vector<TreeNode*>& route) {
        if (start == nullptr) {
            return false;
        }
        route.push_back(start);
        if (start == end) {
            return true;
        }
        if (findRoute(start->left, end, route)) {
            return true;
        }
        if (findRoute(start->right, end, route)) {
            return true;
        }
        route.pop_back();
        return false;
    }
};
