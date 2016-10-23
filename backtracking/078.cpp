class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size(); ++i) {
            int cursize = res.size();
            for (int j = 0; j < cursize; ++j) {
                vector<int> newres = res[j];
                newres.push_back(nums[i]);
                res.push_back(newres);
            }
        }
        return res;
    }
};
