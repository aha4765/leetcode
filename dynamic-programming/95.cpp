// Read the discussion before getting the answer
// well, empty vector and vector with nullptr is different

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
    vector<TreeNode*> generateTrees(int n) {
        //vector<TreeNode*> res;
        //res = helper(1, n);
        if (n == 0) {return vector<TreeNode*>{};}
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        else if (start == end) {
            TreeNode* temp = new TreeNode(start);
            res.push_back(temp);
            return res;
        }
        else {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> leftgrp = helper(start, i - 1);
                vector<TreeNode*> rightgrp = helper(i + 1, end);
                for (auto leftnode : leftgrp) {
                    for (auto rightnode : rightgrp) {
                        TreeNode* temp = new TreeNode(i);
                        temp->left = leftnode;
                        temp->right = rightnode;
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};
