class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int size = nums.size();
        
        for (i = 0; i < size; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
        }
        
        for (; j < size; ++j) {
            nums[j] = 0;
        }
    }
};
