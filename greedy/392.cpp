class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        for (;i < s.size(); ++i) {
            for (; j < t.size(); ++j) {
                if (t[j] == s[i]) {
                    break;
                }
            }
            if (j == t.size()) {
                break;
            }
            ++j;
        }
        if (i == s.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};
