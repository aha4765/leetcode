class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<vector<int>>> res;
        vector<vector<int>> cur(n, vector<int>(n, 0));
        helper(res, cur, 0, n);
        
        vector<vector<string>> qs;
        for (int i = 0; i < res.size(); ++i) {
            vector<vector<int>> temp1 = res[i];
            vector<string> temp1str;
            for (int j = 0; j < temp1.size(); ++j) {
                vector<int> temp2 = temp1[j];
                string temp2str = "";
                for (int k = 0; k < temp2.size(); ++k) {
                    temp2str += (temp2[k] == 0 ? '.' : 'Q');
                }
                temp1str.push_back(temp2str);
            }
            qs.push_back(temp1str);
        }
        return qs;
    }
    
    int helper(vector<vector<vector<int>>>& res, vector<vector<int>>& cur, int currow, int n) {
        if (currow == n) {
            res.push_back(cur);
        }
        for (int i = 0; i < n; ++i) {
            if (isvalid(cur, currow, i, n)) {
                cur[currow][i] = 1;
                helper(res, cur, currow+1, n);
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
