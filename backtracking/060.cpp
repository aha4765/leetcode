class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        --k;
        permutation.push_back(1);
        for (int i = 1; i <= n; ++i) {
            permutation.push_back(i*permutation[i-1]);
        }
        
        list<int> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back(i+'1');
        }
        for (int i = 1; i <= n; ++i) {
            int pos = k/permutation[n-i];
            auto it = nums.begin();
            for (int i = 0; i < pos; ++i) {
                ++it;
            }
            res += *it;
            nums.erase(it);
            k %= permutation[n-i];
        }
        return res;
    }
    
private:
    vector<int> permutation;
};
