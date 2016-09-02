// Get idea from discussion

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        
        int rind = 0;
        int cind = ncol - 1;
        
        while ((rind < nrow) && (cind >= 0)) {
            if (target == matrix[rind][cind]) {
                return true;
            }
            else if (target < matrix[rind][cind]) {
                --cind;
            }
            else {
                ++rind;
            }
        }
        return false;
    }
};
