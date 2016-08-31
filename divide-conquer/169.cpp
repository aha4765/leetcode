// 1. be familiar with other stl containers, such as map, unordered_map, priority_queue etc.
// 2. There is a more briliant method in the discussion.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                ++record[nums[i]];
            }
            else {
                record[nums[i]] = 1;
            }
        }
        for (map<int, int>::iterator it = record.begin(); it != record.end(); ++it) {
            if (it->second > nums.size()/2) {
                return it->first;
            }
        }
        return 0;
    }
};
