class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strlen = strs.size();
        vector<vector<vector<int>>> array(strlen+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        
        for (int i = 0; i < strs.size(); ++i) {
            for (int mi = 0; mi <= m; mi++) {
                for (int ni = 0; ni <= n; ni++) {
                    int zero = 0, one = 0;
                    getzeroones(strs[i], zero, one);
                    if (mi < zero || ni < one) {
                        array[i+1][mi][ni] = array[i][mi][ni];
                    }
                    else {
                        array[i+1][mi][ni] = max(array[i][mi][ni], 1+array[i][mi-zero][ni-one]);
                    }
                }
            }
        }
        return array[strlen][m][n];
    }
    
private:
    void getzeroones(const string& str, int& zero, int& one) {
        zero = 0;
        one = 0;
        for (int i = 0; i <str.length(); ++i) {
            if (str[i] == '0') {
                zero++;
            }
            else if (str[i] == '1') {
                one++;
            }
        }
        return;
    }
};
