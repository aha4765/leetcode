class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curres(nums);
        
        backtrack(res, nums, curres, 0);
        return res;
    }
    
    int backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& curres, int pos) {
        int size = nums.size();
        if (pos == size) {
            res.push_back(curres);
            return 0;
        }
        for (int i = 0; i <= pos; ++i) {
            swap(curres[i], curres[pos]);
            backtrack(res, nums, curres, pos+1);
            swap(curres[i], curres[pos]);
        }
        return 0;
    }
};
