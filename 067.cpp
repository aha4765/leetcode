class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int n = max(n1, n2);
        int overflow = 0;
        string res;
        for (int i = 0; i < n; ++i) {
            if (getch(a, n1-1-i)+getch(b, n2-1-i)-'0'-'0'+overflow == 0) {
                res += '0';
                overflow = 0;
            }
            else if (getch(a, n1-1-i)+getch(b, n2-1-i)-'0'-'0'+overflow == 1) {
                res += '1';
                overflow = 0;
            }
            else if (getch(a, n1-1-i)+getch(b, n2-1-i)-'0'-'0'+overflow == 2) {
                res += '0';
                overflow = 1;
            }
            else{
                res += '1';
                overflow = 1;
            }
        }
        if (overflow == 1) {
            res += '1';
        }
        for (int i = 0; i < res.size()/2; ++i) {
            swap(res[i], res[res.size()-1-i]);
        }
        return res;
    }
    
    char getch(string& s, int i) {
        if (i < 0) {
            return '0';
        }
        else {
            return s[i];
        }
    }
};
