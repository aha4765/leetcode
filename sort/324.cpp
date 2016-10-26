// Takes me quite a time to understand this solution

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // find the median
        int n = nums.size();
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        
        int median = *it;
        
        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            if (nums[newindex(j, n)] > median) {
                swap(nums[newindex(i, n)], nums[newindex(j, n)]);
                ++i;
                ++j;
            }
            else if (nums[newindex(j, n)] < median) {
                swap(nums[newindex(j, n)], nums[newindex(k, n)]);
                --k;
            }
            else {
                ++j;
            }
        }
    }
    
    int newindex(int i, int n) {
        return ((1+i*2)%(n|1));
    }
};
