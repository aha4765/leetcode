// see discussion, it may be different

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int table[10];
        table[0] = 10;
        table[1] = 9*9;
        table[2] = 9*8*9;
        table[3] = 9*8*7*9;
        table[4] = table[3] * 6;
        table[5] = table[4] * 5;
        table[6] = table[5] * 4;
        table[7] = table[6] * 3;
        table[8] = table[7] * 2;
        table[9] = table[8] * 1;
        
        if (n == 0) return 1;
        int sum = 0;
        for (int i = 0; i <n; ++i) {
            sum += table[i];
        }
        return sum;
    }
};
