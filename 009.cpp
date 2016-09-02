// negative number is not palindrome

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s;
        while(x != 0) {
            s.push_back(x%10+'0');
            x /= 10;
        }
        int n = s.size();
        for (int i = 0; i < n/2; ++i) {
            if (s[i] != s[n-1-i]) {
                return false;
            }
        }
        return true;
    }
};
