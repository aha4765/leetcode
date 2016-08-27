// leetcode complains about memory limit, but my own test is OK.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> trim;
        trim.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == trim.back()) continue;
            trim.push_back(nums[i]);
        }
        n = trim.size();
        vector<vector<int> > table(n+1, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            table[n][i] = 0;
        }
        int res = -1;
        for (int i = 1; i <=n; ++i) {
            res = res > (1 + helper(trim, i, i - 1, table)) ? res : (1 + helper(trim, i, i - 1, table));
        }
        return res;
    }
    
    int helper(vector<int>& nums, int curind, int preind, vector<vector<int> >& table) {
        if (table[curind][preind] != -1) return table[curind][preind];
        int max = -1;
        for (int i = curind; i < nums.size(); ++i) {
            if (nums[i] > nums[preind]) {
                max = max > (1 + helper(nums, i + 1, i, table)) ? max : (1 + helper(nums, i + 1, i, table));
            }
        }
        if (max == -1) {
            table[curind][preind] = 0;
        }
        else {
            table[curind][preind] = max;
        }
        return table[curind][preind];
    }
};
