// Most naive approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((nums[i] + nums[j]) == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

// Approach from discussion, pay attention to difference in unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> table;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int val = target - nums[i];
            if (table.find(val) != table.end()) {
                res.push_back(table[val]);
                res.push_back(i);
                break;
            }
            else {
                table[nums[i]] = i;
            }
        }
        return res;
    }
};
