class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(i%2 ? i/2+1 : n-i/2);
        }
        if (k%2 == 0) {
            int num = k/2+1;
            for (int i = 0; i < n-k; ++i) {
                result.push_back(num++);
            }
        }
        else {
            int num = n-(k+1)/2;
            for (int i = 0; i < n-k; ++i) {
                result.push_back(num--);
            }
        }
        return result;
    }
};
