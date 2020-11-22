
// brute force
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        for (int i = 0; i < nums.length; ++i) {
            int sum = nums[i];
            for (int j = i+1; j < nums.length; ++j) {
                sum += nums[j];
                if ((sum == 0 && k == 0) || (k!=0 && sum%k == 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int[] runsum = new int[nums.length];
        runsum[0] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            runsum[i] = runsum[i-1] + nums[i];
        }
        
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                int sum;
                if (i == 0) {
                    sum = runsum[j];
                }
                else {
                    sum = runsum[j] - runsum[i-1];
                }
                if ((sum == 0 && k == 0) || (k!=0 && sum%k == 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}
