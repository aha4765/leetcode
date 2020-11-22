class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p == "") return 0;
        vector<int> sublen(26, 0);
        int maxlen = 1;
        sublen[p[0]-'a'] = 1;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i]-p[i-1] == 1 || p[i-1]-p[i] == 25) {
                maxlen++;
            }
            else {
                maxlen = 1;
            }
            sublen[p[i]-'a'] = max(sublen[p[i]-'a'], maxlen);
        }
        
        int ret = 0;
        for (int i = 0; i < sublen.size(); ++i) {
            ret += sublen[i];
        }
        return ret;
    }
};
