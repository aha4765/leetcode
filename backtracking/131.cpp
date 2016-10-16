class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curvec;
        
        helper(s, res, curvec);
        return res;
    }
    
    int helper(string s, vector<vector<string>>& res, vector<string>& curres) {
        if (s.size() == 0) {
            res.push_back(curres);
            return 0;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (ispalin(s.substr(0, i+1))) {
                curres.push_back(s.substr(0, i+1));
                if (s.size() == 1) {
                    helper(string(""), res, curres);
                }
                else {
                    helper(s.substr(i+1, s.size()-i-1), res, curres);
                }
                curres.pop_back();
            }
        }
        return 0;
    }
    
    bool ispalin(string s) {
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }
        return true;
    }
};
