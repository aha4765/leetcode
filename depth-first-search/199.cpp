// This is the solution with BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // first try bfs
class Solution {
public:
    struct DataSet {
        TreeNode* node_;
        int level_;
        
        DataSet(TreeNode* node, int level) {
            node_ = node;
            level_ = level;
        }
    };
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<DataSet> visited;
        visited.push(DataSet(root, 0));
        int curlevel = -1;
        while (!visited.empty()) {
            DataSet cur = visited.front();
            visited.pop();
            if (curlevel < cur.level_) {
                res.push_back(cur.node_->val);
                curlevel = cur.level_;
            }
            if (cur.node_->right != nullptr) {
                visited.push(DataSet(cur.node_->right, cur.level_+1));
            }
            if (cur.node_->left != nullptr) {
                visited.push(DataSet(cur.node_->left, cur.level_+1));
            }
        }
        return res;
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
 // then try dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        dfsHelper(root, 0, res);
        return res;
    }
    int dfsHelper(TreeNode* node, int level, vector<int>& res) {
        if (level >= res.size()) {
            res.push_back(node->val);
        }
        if (node->right != nullptr) {
            dfsHelper(node->right, level+1, res);
        }
        if (node->left != nullptr) {
            dfsHelper(node->left, level+1, res);
        }
        return 0;
    }
};
