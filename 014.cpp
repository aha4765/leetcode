class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0) return res;
        int idx = 0;
        for (idx = 0; idx < strs[0].size(); ++idx) {
            char temp = strs[0][idx];
            for (int i = 1; i < strs.size(); ++i) {
                if ((idx >= strs[i].size()) || (strs[i][idx] != temp)) {
                    return res;
                }
            }
            res.append(1, temp);
        }
        return res;
    }
};
