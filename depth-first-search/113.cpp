// dfs
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> curnode;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        dfs(root, curnode, res, sum);
        return res;
    }
    
    int dfs(TreeNode* node, vector<int>& curnode, vector<vector<int>>& res, int expect) {
        assert(node != nullptr);
        curnode.push_back(node->val);
        if ((node->left == nullptr) && (node->right == nullptr)) {
            if (node->val == expect) {
                res.push_back(curnode);
            }
            return 0;
        }
        if (node->left != nullptr) {
            dfs(node->left, curnode, res, expect - node->val);
            //curnode.erase(curnode.end());
            curnode.pop_back();
        }
        if (node->right != nullptr) {
            dfs(node->right, curnode, res, expect - node->val);
            //curnode.erase(curnode.end());
            curnode.pop_back();
        }
        return 0;
    }
};

// The following backtrace makes more sense, and it is from the discussion
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};
