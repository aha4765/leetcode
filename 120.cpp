class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int nrow = triangle.size();
        if (nrow == 1) return triangle[0][0];
        vector<int> pre(nrow, -1);
        vector<int> cur(nrow, -1);
        
        pre[0] = triangle[0][0];
        for (int i = 1; i < nrow; ++i) {
            cur[0] = pre[0] + triangle[i][0];
            cur[i] = pre[i-1] + triangle[i][i];
            for (int j = 1; j < i; ++j) {
                cur[j] = (pre[j-1] < pre[j] ? pre[j-1] : pre[j]) + triangle[i][j];
            }
            pre = cur;
        }
        int res = INT_MAX;
        for (int i = 0; i < nrow; ++i) {
            res = res < cur[i] ? res : cur[i];
        }
        return res;
    }
};
