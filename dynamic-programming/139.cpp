class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        // have an array, array[i] denotes whether s[0..i-1] is valid or not, 1 is valid, 0 is not
        // array[i] = 1 if array[k] == 1 && s[k...i-1] is in wordDict k in [0 -- i-1]
        int size = s.size();
        vector<int> array(size+1, 0);
        array[0] = 1;
        for (int i = 1; i <= size; ++i) {
            for (int k = 0; k < i; ++k) {
                if ((array[k] == 1) && (wordDict.find(s.substr(k, i-k)) != wordDict.end())) {
                    array[i] = 1;
                    break;
                }
            }
        }
        return array[size] == 1;
    }
};
