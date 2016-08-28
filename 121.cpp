class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int min = prices[0];
        int profit = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            profit = profit > (prices[i] - min) ? profit : (prices[i] - min);
            min = min < prices[i] ? min : prices[i];
        }
        return profit > 0 ? profit : 0;
    }
};

// another problem with different format is to find the maximum sum of
// contiguous subarray.
