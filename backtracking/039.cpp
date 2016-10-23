class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(candidates, res, cur, target, 0);
        return res;
    }
    
    int helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int target, int index) {
        if (target == 0) {
            res.push_back(cur);
            return 0;
        }
        else if (target < 0) {
            return 0;
        }
        
        if (index >= nums.size()) {
            return 0;
        }
        
        int val = nums[index];
        for (int i = 0; i <= target/val; ++i) {
            helper(nums, res, cur, target - i*val, index+1);
            cur.push_back(val);
        }
        for (int i = 0; i <= target/val; ++i) {
            cur.pop_back();
        }
        
        return 0;
    }
};
