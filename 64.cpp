class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        
        if ((nrow == 0) || (ncol == 0)) return 1;
        
        vector<vector<int> > table(nrow, vector<int>(ncol, 0));
        table[0][0] = grid[0][0];
        for (int i = 1; i < ncol; ++i) {
            table[0][i] = table[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < nrow; ++i) {
            table[i][0] = table[i-1][0] + grid[i][0];
        }
        
        for (int i = 1; i < nrow; ++i) {
            for (int j = 1; j < ncol; ++j) {
                table[i][j] = (table[i-1][j] < table[i][j-1] ? table[i-1][j] : table[i][j-1]) + grid[i][j];
            }
        }
        return table[nrow-1][ncol-1];
    }
};
