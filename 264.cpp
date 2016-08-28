// have three index, each points to the ugly number, which multiplied by 2/3/5 
// is just bigger than the current ugly number.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        ugly.push_back(1);
        int l2 = 0, l3 = 0, l5 = 0;
        for (int i = 1; i < n; ++i) {
            int res = min(ugly[l2]*2, ugly[l3]*3, ugly[l5]*5);
            if (res == ugly[l2]*2) {
                ++l2;
            }
            // cannot use else here, since it may happen that candidates 
            // are the same
            if (res == ugly[l3]*3) {
                ++l3;
            }
            if (res == ugly[l5]*5) {
                ++l5;
            }
            ugly.push_back(res);
        }
        return ugly[n-1];
    }
    
    int min(int i, int j, int k) {
        return (i < j ? i : j) < k ? (i < j ? i : j) : k;
    }
};
