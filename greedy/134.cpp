class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> left;
        for (int i = 0; i < gas.size(); ++i) {
            left.push_back(gas[i] - cost[i]);
        }
        // find the first switch point from negative to positive
        bool nflag = false;
        int start = -1;
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] < 0) {
                nflag = true;
            }
            if ((left[i] >= 0) && (nflag == true)) {
                start = i;
                break;
            }
        }
        // since solution guaranteed to be unique, so if start == -1, then no solution
        if (start == -1) {
            if (gas.size() != 1) {
                return -1;
            }
            else {
                if (left[0] >= 0) {
                    return 0;
                }
                else {
                    return -1;
                }
            }
        }
        int count = 0;
        int sum = 0;
        int pos = start;
        int end = start == 0 ? gas.size() - 1 : start - 1;
        while (count < gas.size()) {
            if (sum == 0) {
                pos = start;
                if (pos == end) {
                    return -1;
                }
            }
            sum += left[start];
            start = (start + 1)%gas.size();
            if (sum < 0) {
                sum = 0;
                count = 0;
            }
            else {
                ++count;
            }
        }
        return pos;
    }
};
