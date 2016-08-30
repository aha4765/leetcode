// performance can be improved

class Solution {
public:
    int numSquares(int n) {
        vector<int> table(n+1, -1);
        table[0] = 0;
        for (int i = 1; i*i <= n; ++i) {
            table[i*i] = 1;
        }
        return helper(n, table);
    }
    
    int helper(int n, vector<int>& table) {
        if (table[n] != -1) return table[n];
        int ret = INT_MAX;
        for (int i = 1; i*i < n; ++i) {
            ret = ret < (helper(n-i*i, table) + 1) ? ret : (helper(n-i*i, table) + 1);
        }
        table[n] = ret;
        return ret;
    }
};
