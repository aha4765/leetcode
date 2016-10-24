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
