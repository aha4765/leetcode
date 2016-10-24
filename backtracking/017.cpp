class Solution {
public:
    vector<string> letterCombinations(string digits) {
        table = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}
            , {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        
        vector<string> res;
        if (digits == "") return res;
        string cur;
        helper(digits, res, cur, 0);
        return res;
    }
    
    int helper(string& digits, vector<string>& res, string& cur, int start) {
        if (start == digits.size()) {
            res.push_back(cur);
            return 0;
        }
        for (char temp : table[digits[start]-'0']) {
            cur += temp;
            helper(digits, res, cur, start+1);
            cur.pop_back();
        }
        return 0;
    }
    
private:
    vector<vector<char>> table;
};
