// check the discussion, others should have better solution.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> table(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            table[i] = table[i-1] + nums[i-1];
        }
        int min = table[0];
        int ret = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            ret = ret > (table[i] - min) ? ret : (table[i] - min);
            min = min < table[i] ? min : table[i];
        }
        return ret;
    }
};
