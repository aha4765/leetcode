// well, first I think subarray with zero elements is possible
// but it is not allowed

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> pos, neg;
        if (nums[0] == 0) {
            pos.push_back(0);
            neg.push_back(0);
        }
        else if (nums[0] < 0) {
            pos.push_back(nums[0]);
            neg.push_back(nums[0]);
        }
        else {
            pos.push_back(nums[0]);
            neg.push_back(nums[0]);
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                neg.push_back(neg[i-1] * nums[i] < nums[i] ? neg[i-1] * nums[i] : nums[i]);
                pos.push_back(pos[i-1] * nums[i] > nums[i] ? pos[i-1] * nums[i] : nums[i]);
            }
            else if (nums[i] < 0) {
                pos.push_back(neg[i-1] * nums[i] > nums[i] ? neg[i-1] * nums[i] : nums[i]);
                neg.push_back(pos[i-1] * nums[i] < nums[i] ? pos[i-1] * nums[i] : nums[i]);
            }
            else {
                pos.push_back(0);
                neg.push_back(0);
            }
        }
        
        int res = INT_MIN;
        for (int i = 0; i < pos.size(); ++i) {
            res = res > pos[i] ? res : pos[i];
        }
        return res;
    }
};
