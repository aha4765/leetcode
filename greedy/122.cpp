class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        bool buy = true;
        if (prices.empty()) {
            return 0;
        }
        for (int i = 0; i < (prices.size() - 1); ++i) {
            if ((prices[i+1] > prices[i]) && (buy == true)) {
                res -= prices[i];
                buy = false;
            }
            else if ((prices[i+1] < prices[i]) && (buy == false)) {
                res += prices[i];
                buy = true;
            }
        }
        if (buy == false) {
            res += prices[prices.size() - 1];
        }
        return res;
    }
};
