// performance not good

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n1 = matrix.size();
        if (n1 == 0) return 0;
        int n2 = matrix[0].size();
        if (n2 == 0) {
            return 0;
        }
        
        int size = 0;
        for (size = 0; size < (n1 < n2 ? n1 : n2); size++) {
            int onecnt = 0;
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n2; ++j) {
                    if (matrix[i][j] == '1') {
                        ++onecnt;
                        break;
                    }
                }
                if (onecnt != 0) {
                    break;
                }
            }
            if (onecnt == 0) {
                break;
            }
            for (int i = 0; i < n1-1; ++i) {
                for (int j = 0; j < n2-1; ++j) {
                    if ((matrix[i][j] != '0') && (matrix[i+1][j] != '0') && (matrix[i][j+1] != '0') && (matrix[i+1][j+1] != '0')) {
                        matrix[i][j] = 'k';
                    }
                }
            }
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n2; ++j) {
                    if (matrix[i][j] == '1') {
                        matrix[i][j] = '0';
                    }
                    else if (matrix[i][j] == 'k') {
                        matrix[i][j] = '1';
                    }
                }
            }
        }
        return size*size;
    }
};
