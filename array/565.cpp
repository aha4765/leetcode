class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> set;
        int len = 0, curlen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int start = i;
            while (set.count(start) == 0) {
                curlen++;
                set.insert(start);
                start = nums[start];
            }
            len = max(len, curlen);
            curlen = 0;
        }
        return len;
    }
};
