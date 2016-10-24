// hash map is a good idea

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        
        for (int i = 0; i < nums1.size(); ++i) {
            set1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i) {
            set2.insert(nums2[i]);
        }
        
        vector<int> res;
        for (auto it = set1.begin(); it != set1.end(); ++it) {
            if (set2.find(*it) != set2.end()) {
                res.push_back(*it);
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        int ind1 = 0;
        int ind2 = 0;
        while ((ind1 < nums1.size()) && (ind2 < nums2.size())) {
            if (nums1[ind1] == nums2[ind2]) {
                res.push_back(nums1[ind1]);
                
                ++ind1;
                while((ind1 < nums1.size()) && (nums1[ind1] == nums1[ind1-1])) {
                    ++ind1;
                }
                
                ++ind2;
                while((ind2 < nums2.size()) && (nums2[ind2] == nums2[ind2-1])) {
                    ++ind2;
                }
            }
            
            if (nums1[ind1] < nums2[ind2]) {
                ++ind1;
                while((ind1 < nums1.size()) && (nums1[ind1] == nums1[ind1-1])) {
                    ++ind1;
                }
            }
            
            if (nums1[ind1] > nums2[ind2]) {
                ++ind2;
                while((ind2 < nums2.size()) && (nums2[ind2] == nums2[ind2-1])) {
                    ++ind2;
                }
            }
        }
        return res;
    }
};
