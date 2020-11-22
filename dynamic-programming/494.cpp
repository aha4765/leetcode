class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findsum(nums, 0, S);
    }
    
private:
    int findsum(vector<int>& nums, int p, int S) {
        if (nums.size() <= p) {
            if (S == 0) return 1;
            else return 0;
        }
        else {
            return findsum(nums, p+1, S-nums[p]) + findsum(nums, p+1, S+nums[p]);
        }
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        result_ = vector<unordered_map<int, int>>(size, unordered_map<int, int>());
        return findsum(nums, 0, S);
    }
    
private:
    int findsum(vector<int>& nums, int p, int S) {
        if (nums.size() <= p) {
            if (S == 0) return 1;
            else return 0;
        }
        else {
            if (result_[p].count(S) != 0) {
                return result_[p][S];
            }
            else {
                result_[p][S] = findsum(nums, p+1, S-nums[p]) + findsum(nums, p+1, S+nums[p]);
                return result_[p][S];
            }
        }
    }
    
    vector<unordered_map<int, int>> result_;
};
