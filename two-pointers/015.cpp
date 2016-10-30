class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if ((i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            for (int j = i+1; j < nums.size() - 1; ++j) {
                if ((j > i+1) && (nums[j] == nums[j-1])) {
                    continue;
                }
                for (int k = j+1; k < nums.size(); ++k) {
                    if ((k > j+1) && (nums[k] == nums[k-1])) {
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if ((i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            for (int j = i+1; j < nums.size() - 1; ++j) {
                if ((j > i+1) && (nums[j] == nums[j-1])) {
                    continue;
                }
                if (binarysearch(nums, j+1, nums.size()-1, 0-nums[i]-nums[j])) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(0-nums[i]-nums[j]);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
    
    bool binarysearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int median = (start + end)/2;
            if (nums[median] < target) {
                start = median + 1;
            }
            else if (nums[median] > target) {
                end = median - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
