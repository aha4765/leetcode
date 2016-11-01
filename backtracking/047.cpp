class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curres;
        vector<bool> used(nums.size(), false);
        backtrack(res, nums, used, curres);
        return res;
    }
    
    int backtrack(vector<vector<int>>& res, vector<int>& nums, vector<bool>& used, vector<int>& curres) {
        int size = nums.size();
        if (curres.size() == size) {
            res.push_back(curres);
            return 0;
        }
        
        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            if (used[i] == false) {
                curres.push_back(nums[i]);
                used[i] = true;
                backtrack(res, nums, used, curres);
                used[i] = false;
                curres.pop_back();
            }
        }
        return 0;
    }
};
