class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        
        // table[i][j] is 1 is s[0...i-1] and p[0...j-1] match
        vector<vector<int>> table(n1+1, vector<int>(n2+1, 0));
        
        table[0][0] = 1;
        for (int i = 1; i <= n1; ++i) {
            table[i][0] = 0;
        }
        for (int i = 2; i <= n2; ++i) {
            if ((p[i-1] == '*') && (table[0][i-2] == 1)) {
                table[0][i] = 1;
            }
        }
        
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (p[j-1] != '*') {
                    if ((table[i-1][j-1] == 1) && ((p[j-1] == s[i-1]) || (p[j-1] == '.'))) {
                        table[i][j] = 1;
                    }
                }
                else {
                    if (table[i][j-2] == 1) {
                        table[i][j] = 1;
                    }
                    else if ((table[i-1][j] == 1) && ((s[i-1] == p[j-2]) || (p[j-2] == '.'))) {
                        table[i][j] = 1;
                    }
                }
            }
        }
        
        return table[n1][n2] == 1;
    }
};
