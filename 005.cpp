// The idea is simple, but the code is not clean

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (s.size() == 1) {
            return s;
        }
        int left = 0, right = 0;
        int maxleft, maxright;
        int maxlen = 0;
        // if the length is odd
        for (int i = 0; i < n; ++i) {
            left = i;
            right = i;
            while ((left >=0) && (right < n)) {
                if (s[left] == s[right]) {
                    if (maxlen < (right - left + 1)) {
                        maxlen = right - left + 1;
                        maxleft = left;
                        maxright = right;
                    }
                    --left;
                    ++right;
                }
                else {
                    break;
                }
            }
        }
        string s1 = s.substr(maxleft, maxright-maxleft+1);
        // if the length is even
        maxlen = 0;
        for (int i = 0; i < n-1; ++i) {
            left = i;
            right = i+1;
            while ((left >=0) && (right < n)) {
                if (s[left] == s[right]) {
                    if (maxlen < (right - left + 1)) {
                        maxlen = right - left + 1;
                        maxleft = left;
                        maxright = right;
                    }
                    --left;
                    ++right;
                }
                else {
                    break;
                }
            }
        }
        string res;
        if (maxlen > s1.size()) {
            res = s.substr(maxleft, maxright-maxleft+1);
        }
        else {
            res = s1;
        }
        return res;
    }
};
