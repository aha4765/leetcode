class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum%2 != 0) {
            return false;
        }
        int arrsize = nums.size();
        // partition[i][j] is true when a subarray from first i elements can sum to j
        vector<vector<bool>> partition(arrsize+1, vector<bool>(sum/2+1, false));
        for (int i = 0; i < arrsize+1; ++i) {
            partition[i][0] = true;
        }
        for (int i = 1; i < sum/2+1; ++i) {
            partition[0][i] = false;
        }
        
        for (int i = 1; i < arrsize+1; ++i) {
            for (int j = 1; j < sum/2+1; ++j) {
                if (partition[i-1][j]) {
                    partition[i][j] = true;
                }
                else if ((j-nums[i-1] >= 0) && (partition[i-1][j-nums[i-1]])) {
                    partition[i][j] = true;
                }
            }
        }
        return partition[arrsize][sum/2];
    }
};
