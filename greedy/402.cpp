class Solution {
public:
    string removeKdigits(string num, int k) {
        string numcpy = num;
        int kcpy = k;
        string res;
        while (kcpy >= 0) {
            res += removeHelper(numcpy, kcpy);
        }
        return trimleadingzero(res);
    }
    
    string removeHelper(string &num, int& k) {
        if (k == 0) {
            k = -1;
            return num;
        }
        if (num.size() == k) {
            k = -1;
            num.erase(num.begin(), num.end());
            return string("");
        }
        int index = 0;
        char minchar = num[0];
        for (int i = 1; i <= k; ++i) {
            if (minchar > num[i]) {
                minchar = num[i];
                index = i;
            }
        }
        k -= index;
        num.erase(0, index+1);
        return string(1, minchar);
    }
    
    string trimleadingzero(string src) {
        int pos = 0;
        for (pos = 0; pos < src.size(); ++pos) {
            if (src[pos] != '0') {
                break;
            }
        }
        
        return pos == src.size() ? string("0") : src.substr(pos, src.size()-pos);
    }
};
