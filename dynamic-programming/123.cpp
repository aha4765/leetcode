#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        
        if (size <= 1) return 0;
        
        vector<vector<int>> table(4, vector<int>(size+1, INT_MIN));
        table[1][0] = 0;
        table[3][0] = 0;
        for (int i = 1; i <= size; ++i) {
            table[0][i] = max(table[0][i-1], 0-prices[i-1]);
            table[1][i] = max(table[1][i-1], table[0][i-1]+prices[i-1]);
            table[2][i] = max(table[2][i-1], table[1][i-1]-prices[i-1]);
            table[3][i] = max(table[3][i-1], table[2][i-1]+prices[i-1]);
        }
        return max(table[1][size], table[3][size]);
    }
};

int main() {
  Solution sol;
  vector<int> test = {2, 1};
  sol.maxProfit(test);
  return 0;
}
