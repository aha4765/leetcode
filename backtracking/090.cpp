// the discuss has better solution

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> curres;
        backtrack(nums, 0, curres, res);
        return res;
    }
    
    int backtrack(vector<int>& nums, int start, vector<int>& curres, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(curres);
            return 0;
        }
        
        int val = nums[start];
        int count = 0;
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] == val) {
                ++count;
            }
            else {
                break;
            }
        }
        for (int i = 0; i <= count; ++i) {
            for (int j = 0; j < i; ++j) {
                curres.push_back(val);
            }
            backtrack(nums, start+count, curres, res);
            for (int j = 0; j < i; ++j) {
                curres.pop_back();
            }
        }
        return 0;
    }
};
