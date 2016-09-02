// digits vector not necessary
// have a better way to check for overflow

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        vector<int> digits;
        int absx;
        absx = x > 0 ? x : (0-x);
        while (absx != 0) {
            digits.push_back(absx%10);
            absx /= 10;
        }
        int64_t res = 0;
        for (int i = 0; i < digits.size(); ++i) {
            res *= 10;
            res += digits[i];
        }
        res = x > 0 ? res : (0-res);
        if ((res > INT_MAX) || (res < INT_MIN)) {
            return 0;
        }
        return res;
    }
};
