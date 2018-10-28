class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int duplicate = 0;
        if (k < 0) {
            return 0;
        }
        if (k == 0) {
            unordered_map<int, int> nummap;
            for (int num : nums) {
                if (nummap.count(num) == 0) {
                    nummap[num] = 1;
                }
                else if (nummap[num] == 1) {
                    nummap[num]++;
                    duplicate++;
                }
                else {
                    nummap[num]++;
                }
            }
            return duplicate;
        }
        unordered_set<int> numset;
        for (int num : nums) {
            numset.insert(num);
        }
        int totalnum = 0;
        for (auto it = numset.begin(); it != numset.end(); ++it) {
            int target = *it + k;
            if (numset.count(target) != 0) {
                totalnum++;
            }
        }
        return totalnum;
    }
};
