class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        if (n == 3) return (nums[0] > nums[1] ? nums[0] : nums[1]) > nums[2] ? (nums[0] > nums[1] ? nums[0] : nums[1]) : nums[2];
        vector<int> tables(nums.size(), -1);
        // if we rob the first house
        tables[0] = nums[0];
        tables[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < n-1; ++i) {
            tables[i] = tables[i-1] > (tables[i-2] + nums[i]) ? tables[i-1] : (tables[i-2] + nums[i]);
        }
        int res = tables[n-2];
        // if we do not rob the first house
        tables[0] = 0;
        tables[1] = nums[1];
        tables[2] = nums[1] > nums[2] ? nums[1] : nums[2];
        for (int i = 3; i < n; ++i) {
            tables[i] = tables[i-1] > (tables[i-2] + nums[i]) ? tables[i-1] : (tables[i-2] + nums[i]);
        }
        res = res > tables[n-1] ? res : tables[n-1];
        return res;
    }
};
