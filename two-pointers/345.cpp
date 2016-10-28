class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        int size = s.size();
        string res = s;
        while (i < j) {
            while (!isvow(res[i]) && (i < j)) {
                ++i;
            };
            if (i >= j) {
                break;
            }
            while (!isvow(res[j]) && (i < j)) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(res[i++], res[j--]);
        }
        return res;
    }
    
    bool isvow(char c) {
        if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
            (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) {
            return true;
        }
        else {
            return false;
        }
    }
};
