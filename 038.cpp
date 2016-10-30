class Solution {
public:
    string countAndSay(int n) {
        string start = "1";
        if (n == 0) {
            return "";
        }
        else if (n == 1) {
            return start;
        }
        for (int i = 1; i < n; ++i) {
            int count = 0;
            string res;
            for (int j = 0; j < start.size(); ++j) {
                char cur = start[j];
                count++;
                if ((j == start.size()-1) || (start[j] != start[j+1])) {
                    res += (count + '0');
                    res += cur;
                    count = 0;
                }
            }
            start = res;
        }
        return start;
    }
};
