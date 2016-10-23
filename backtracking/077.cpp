class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        if (n < k) {
            return res;
        }
        helper(res, cur, 1, k, n);
        return res;
    }
    
    int helper(vector<vector<int>>& res, vector<int>& cur, int start, int left, int n) {
        if (left == 0) {
            res.push_back(cur);
            return 0;
        }
        else if (n-start+1 == left) {
            for (int i = start; i <= n; ++i) {
                cur.push_back(i);
            }
            helper(res, cur, n+1, 0, n);
            for (int i = start; i <= n; ++i) {
                cur.pop_back();
            }
        }
        else {
            helper(res, cur, start+1, left, n);
            cur.push_back(start);
            helper(res, cur, start+1, left-1, n);
            cur.pop_back();
        }
        return 0;
    }
};
