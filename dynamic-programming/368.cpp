// Get the solution after lc discussion
// made several mistakes in corner case and initial value of variable

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<int>{};
        if (n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> table(n, 1);
        vector<int> parent(n, -1);
        int maxind = 0;
        int res = 1;
        for (int i = 1; i < n; ++i) {
            int max = 1;
            int ind = -1;
            for (int j = 0; j < i; ++j) {
                if ((nums[i] % nums[j] == 0) && (max < (table[j] + 1))) {
                    max = (table[j] + 1);
                    ind = j;
                }
            }
            parent[i] = ind;
            table[i] = max;
            if (max > res) {
                res = max;
                maxind = i;
            }
        }
        
        vector<int> result;
        do {
            result.push_back(nums[maxind]);
            maxind = parent[maxind];
        } while (maxind != -1);
        
        return result;
    }
};
