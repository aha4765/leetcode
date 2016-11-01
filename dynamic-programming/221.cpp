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

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if ((matrix.size() == 0) || (matrix[0].size() == 0)) return 0;
        int nx = matrix.size();
        int ny = matrix[0].size();
        
        vector<vector<int>> size(nx, vector<int>(ny, 0));
        int maxsq = 0;
        
        for (int i = 0; i < ny; ++i) {
            size[0][i] = (matrix[0][i] == '1') ? 1 : 0;
            maxsq = max(size[0][i], maxsq);
        }
        for (int i = 0; i < nx; ++i) {
            size[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            maxsq = max(size[i][0], maxsq);
        }
        
        for (int i = 1; i < nx; ++i) {
            for (int j = 1; j < ny; ++j) {
                if (matrix[i][j] == '1') {
                    size[i][j] = min(min(size[i-1][j], size[i][j-1]), size[i-1][j-1]) + 1;
                    maxsq = max(size[i][j], maxsq);
                }
                else {
                    size[i][j] = 0;
                }
            }
        }
        return maxsq*maxsq;
    }
};
