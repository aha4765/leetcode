// check https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
// This solution is simpler and more pretty

class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n+1, 0);
        
        table[0] = 1;
        table[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= (i-1); ++j) {
                table[i] += table[j] * table[i-1-j];
            }
        }
        return table[n];
    }
};
