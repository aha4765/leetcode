class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++n;
                }
            }
        }
        return n;
    }
    
    int dfs(vector<vector<char>>& grid, int x, int y) {
        int xlim = grid.size();
        int ylim = grid[0].size();
        grid[x][y] = 's';
        if ((x > 0) && (grid[x-1][y] == '1')) {
            dfs(grid, x-1, y);
        }
        if ((y > 0) && (grid[x][y-1] == '1')) {
            dfs(grid, x, y-1);
        }
        if ((x < (xlim-1)) && (grid[x+1][y] == '1')) {
            dfs(grid, x+1, y);
        }
        if ((y < (ylim-1)) && (grid[x][y+1] == '1')) {
            dfs(grid, x, y+1);
        }
        return 0;
    }
    
};
