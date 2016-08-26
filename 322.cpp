//performance not good
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount+1, -1);
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] <= amount) {
                table[coins[i]] = 1;
            }
        }
        table[0] = 0;
        int res = helper(coins, amount, table, amount+1);
        if (res > amount) {
            return -1;
        }
        else {
            return res;
        }
    }
    
    int helper(vector<int>& coins, int amount, vector<int>& table, int ceiling) {
        if (amount == 0) return 0;
        if (amount < 0) return ceiling;
        if (table[amount] != -1) return table[amount];
        int min = ceiling;
        for (int i = 0; i < coins.size(); ++i) {
            min = min < (helper(coins, amount - coins[i], table, ceiling) + 1) ? min : (helper(coins, amount - coins[i], table, ceiling) + 1);
        }
        table[amount] = min;
        return table[amount];
    }
};
