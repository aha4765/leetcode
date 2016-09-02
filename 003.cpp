// The idea is the same, but the code should be cleaner

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) return 1;
        if (s.size() == 0) return 0;
        int n = s.size();
        unordered_map<char, int> record;
        record[s[0]] = 0;
        int i = 0, j = 1;
        int len = 1;
        while (j < n) {
            unordered_map<char, int>::iterator it;
            if ((it = record.find(s[j])) == record.end()) {
                record[s[j]] = j;
                ++j;
            }
            else {
                len = len > (j-i) ? len : (j-i);
                while (i <= it->second) {
                    record.erase(s[i]);
                    ++i;
                }
                record[s[j]] = j;
                ++j;
            }
        }
        len = len > (j-i) ? len : (j-i);
        return len;
    }
};
