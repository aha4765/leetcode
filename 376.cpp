// This is my own solution, O(n^2) time complexity

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> inc(n, 0);
        vector<int> dec(n, 0);
        
        inc[0] = 1;
        dec[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            int incres = 0;
            int decres = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    incres = incres > (dec[j] + 1) ? incres : (dec[j] + 1);
                    decres = decres > 1 ? decres : 1;
                }
                else if (nums[i] == nums[j]) {
                    incres = incres > inc[j] ? incres : inc[j];
                    decres = decres > dec[j] ? decres : dec[j];
                }
                else {
                    incres = incres > 1 ? incres : 1;
                    decres = decres > (inc[j] + 1) ? decres : (inc[j] + 1);
                }
            }
            inc[i] = incres;
            dec[i] = decres;
        }
        return inc[n-1] > dec[n-1] ? inc[n-1] : dec[n-1];
    }
};
