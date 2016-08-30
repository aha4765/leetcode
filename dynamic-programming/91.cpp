// be careful about the inital comparison
// also output 0 is string not decodable

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0) return 0;
        if (size == 1) return s[0] == '0' ? 0 : 1;
        vector<int> table(size, -1);
        if (isvalid(s[0])) table[0] = 1;
        else table[0] = 0;
        
        if (isvalid(s[0], s[1]) && isvalid(s[1]) && isvalid(s[0])) table[1] = 2;
        else if ((isvalid(s[0]) && isvalid(s[1])) || (isvalid(s[0], s[1]))) table[1] = 1;
        else table[1] = 0;
        
        for (int i = 2; i < size; ++i) {
            int ret = 0;
            if (isvalid(s[i])) ret += table[i-1];
            if (isvalid(s[i-1], s[i])) ret += table[i-2];
            table[i] = ret;
        }
        return table[size - 1];
    }
    
    bool isvalid(const char a, const char b) {
        if (a == '1') return true;
        if ((a == '2') && (b >= '0') && (b <= '6')) return true;
        return false;
    }
    
    bool isvalid(const char a) {
        if (a != '0') return true;
        return false;
    }
};
