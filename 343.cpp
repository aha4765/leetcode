class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> table(n+1, -1);
        table[0] = 0;
        table[1] = 1;
        table[2] = 2;
        table[3] = 3;
        return helper(n, table);
    }
    
    int helper(int n, vector<int>& table) {
        if (table[n] != -1) return table[n];
        int max = -1;
        for (int i = 1; i <= n/2; i++) {
            max = max > helper(i, table) * helper(n-i, table) ? max : helper(i, table) * helper(n-i, table);
        }
        table[n] = max;
        return max;
    }
};
