class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price, special, needs, 0);
    }
    
private:
    // The lowest price of buying with offer from offeroffset
    int helper(vector<int> price, vector<vector<int>> special, vector<int> needs, int offeroffset) {
        int totalcost = INT_MAX;
        
        int offersize = special.size();
        if (offeroffset >= offersize) {
            totalcost = 0;
            for (int i = 0; i < needs.size(); ++i) {
                totalcost += price[i]*needs[i];
            }
            return totalcost;
        }
        for (int j = 0; ; ++j) {
            if (exceeds(special[offeroffset], needs, j)) {
                break;
            }
            else {
                vector<int> tempneed = needs;
                for (int k = 0; k < needs.size(); ++k) {
                    tempneed[k] = needs[k] - special[offeroffset][k]*j;
                }
                totalcost = min(totalcost, special[offeroffset].back()*j+helper(price, special, tempneed, offeroffset+1));
            }
        }
        return totalcost;
    }
    
    bool exceeds(vector<int> offer, vector<int> needs, int offnum) {
        for (int i = 0; i < needs.size(); ++i) {
            if (offer[i]*offnum > needs[i]) {
                return true;
            }
        }
        return false;
    }
};
