class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        
        int arrsize = A.size();
        
        vector<vector<bool>> isslice(arrsize, vector<bool>(arrsize, false));
        int cnt = 0;
        for (int i = 0; i < arrsize-2; ++i) {
            for (int j = i+2; j < arrsize; ++j) {
                if (i > 0) {
                    if (isslice[i-1][j] == true) {
                        isslice[i][j] = true;
                        cnt++;
                        continue;
                    }
                }
                if (j == i+2) {
                    if (A[i+1] - A[i] == A[i+2] - A[i+1]) {
                        isslice[i][j] = true;
                        cnt++;
                        continue;
                    }
                }
                if (isslice[i][j-1] == true && (A[j] - A[j-1] == A[j-1] - A[j-2])) {
                    isslice[i][j] = true;
                    cnt++;
                    continue;
                }
            }
        }
        return cnt;
    }
};
