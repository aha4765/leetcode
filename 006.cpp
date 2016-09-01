// in the beginning I did not realize that numRows = 1 should be treated specially

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = s.size();
        vector<vector<char>> table(numRows, vector<char>(0, '0'));
        int curind = 0;
        bool inc = true;
        for (int i = 0; i < n; ++i) {
            if (curind == numRows) {
                if (numRows == 1) {
                    curind = 0;
                }
                else {
                    curind = numRows - 2;
                }
                inc = false;
            }
            if (curind == -1) {
                if (numRows == 1) {
                    curind = 0;
                }
                else {
                    curind = 1;
                }
                inc = true;
            }
            table[curind].push_back(s[i]);
            if (inc) {
                ++curind;
            }
            else {
                --curind;
            }
        }
        for (int i = 0; i < numRows; ++i) {
            for (auto temp : table[i]) {
                res.push_back(temp);
            }
        }
        return res;
    }
};

// cleaner from discussion

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = s.size();
        vector<vector<char>> table(numRows, vector<char>(0, '0'));
        int i = 0;
        while (i < n) {
            for (int idx = 0; (idx < numRows) && (i < n); ++idx) {
                table[idx].push_back(s[i++]);
            }
            if (numRows > 1) {
                for (int idx = numRows-2; (idx > 0) && (i < n); --idx) {
                    table[idx].push_back(s[i++]);
                }
            }
        }
        for (i = 0; i < numRows; ++i) {
            for (auto temp : table[i]) {
                res.push_back(temp);
            }
        }
        return res;
    }
};
