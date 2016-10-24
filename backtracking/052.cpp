class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<vector<int>> cur(n, vector<int>(n, 0));
        helper(cnt, cur, 0, n);
        return cnt;
    }
    
     int helper(int& cnt, vector<vector<int>>& cur, int currow, int n) {
        if (currow == n) {
            ++cnt;
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (isvalid(cur, currow, i, n)) {
                cur[currow][i] = 1;
                helper(cnt, cur, currow+1, n);
                cur[currow][i] = 0;
            }
        }
        return 0;
    }
    
    bool isvalid(vector<vector<int>>& cur, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (cur[i][col] == 1) {
                return false;
            }
            if ((col+row-i < n) && (cur[i][col+row-i] == 1)) {
                return false;
            }
            if ((col-row+i >= 0) && (cur[i][col-row+i] == 1)) {
                return false;
            }
        }
        return true;
    }
};
