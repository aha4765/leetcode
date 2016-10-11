class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            nums[i] += i;
        }
        int startpos = 0;
        int endpos = 0;
        while (startpos < (nums.size() - 1)) {
            if (nums[startpos] == startpos) return false;
            else {
                int dest = findmax(nums, startpos+1, nums[startpos]);
                startpos = dest;
            }
        }
        return true;
    }
    
    int findmax(vector<int>& nums, int start, int end) {
        int max = nums[start];
        int pos = start;
        
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                pos = i;
            }
        }
        return pos;
    }
};
