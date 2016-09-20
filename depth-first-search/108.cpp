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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructBST(vector<int>&nums, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* root = new TreeNode(nums[(start+end)/2]);
        root->left = constructBST(nums, start, (start+end)/2-1);
        root->right = constructBST(nums, (start+end)/2+1, end);
        return root;
    }
};
