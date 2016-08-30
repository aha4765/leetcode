// Get more familiar with string operation and functions.

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int pos = -1;
        while ((pos = input.find('+', pos+1)) != string::npos) {
            for (auto temp1 : diffWaysToCompute(input.substr(0, pos))) {
                for (auto temp2 : diffWaysToCompute(input.substr(pos+1, input.size()-1-pos))) {
                    res.push_back(temp1 + temp2);
                }
            }
        }
        pos = -1;
        while ((pos = input.find('-', pos+1)) != string::npos) {
            for (auto temp1 : diffWaysToCompute(input.substr(0, pos))) {
                for (auto temp2 : diffWaysToCompute(input.substr(pos+1, input.size()-1-pos))) {
                    res.push_back(temp1 - temp2);
                }
            }
        }
        pos = -1;
        while ((pos = input.find('*', pos+1)) != string::npos) {
            for (auto temp1 : diffWaysToCompute(input.substr(0, pos))) {
                for (auto temp2 : diffWaysToCompute(input.substr(pos+1, input.size()-1-pos))) {
                    res.push_back(temp1 * temp2);
                }
            }
        }
        if (res.size() == 0) {
            res.push_back(stoi(input));
        }
        return res;
    }
};
