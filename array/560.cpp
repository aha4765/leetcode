class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> sumarr(size, 0);
        
        sumarr[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sumarr[i] = sumarr[i-1] + nums[i];
        }
        
        int cnt = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                if (sumarr[j] - sumarr[i] + nums[i] == k) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
