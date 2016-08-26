// performance not good
// I forgot the corner case of empty or 1 element array in the first submission

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> table(prices.size(), -1);
        return helper(prices, 0, table);
    }
    
    int helper(vector<int>&prices, int start, vector<int>& table) {
        if (start >= (prices.size() - 1)) return 0;
        if (table[start] != -1) return table[start];
        int minprice = prices[start];
        int maxprofit = -1;
        for (int i = start+1; i < prices.size(); ++i ) {
            minprice = minprice < prices[i] ? minprice : prices[i];
            maxprofit = maxprofit > (helper(prices, i+2, table) + prices[i] - minprice) ? maxprofit : (helper(prices, i+2, table) + prices[i] - minprice);
        }
        table[start] = maxprofit;
        return table[start];
    }
};
