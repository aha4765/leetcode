class Solution {
public:
    string reverseString(string s) {
        string res = s;
        int i = 0, j = res.size() - 1;
        
        while (i < j) {
            swap(res[i++], res[j--]);
        }
        return res;
    }
};
