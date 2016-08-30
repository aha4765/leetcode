/ DO NOT forget the corner case of empty input

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> table(nums.size(), -1);
        table[0] = nums[0];
        table[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        return helper(nums, nums.size()-1, table);
    }
    int helper(const vector<int>& nums, int n, vector<int>& table) {
        if (table[n] != -1) return table[n];
        
        int res = helper(nums, n-1, table) > (helper(nums, n-2, table) + nums[n]) ? helper(nums, n-1, table) : (helper(nums, n-2, table) + nums[n]);
        table[n] = res;
        return res;
    }
};
