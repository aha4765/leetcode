class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        vector<int> curres;
        combSumHelp(k, n, curres, res, 0);
        return res;
    }
    
    void combSumHelp(int k, int n, vector<int>& curres, vector<vector<int>>& res, int start) {
        if (k == 0) {
            if (n == 0) {
                res.push_back(curres);
                return;
            }
            else {
                return;
            }
        }
            
        for (int i = start; i < (cand.size() - k + 1); ++i) {
            // push into
            curres.push_back(cand[i]);
            combSumHelp(k-1, n-cand[i], curres, res, i+1);
            // pop out, then it's where backtracking happens
            curres.pop_back();
        }
    }
    
private:
    vector<int> cand{1,2,3,4,5,6,7,8,9};
};
