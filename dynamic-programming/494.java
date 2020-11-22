class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
        }
        if ((sum + S) % 2 != 0) {
            return 0;
        }
        if (sum < Math.abs(S)) {
            return 0;
        }
        
        int target = (sum + S) / 2;
        // dp[i] is the number of combinations to get sum of i
        int[] dp = new int[target+1];
        dp[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
}
