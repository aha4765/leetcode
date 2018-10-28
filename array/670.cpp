#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<int> digitsheap;
        vector<int> digitsvec;
        
        while (num > 0) {
            int digit = num%10;
            num /= 10;
            digitsvec.push_back(digit);
            digitsheap.push(digit);
        }
        if (digitsvec.empty()) {
            return 0;
        }
        
        for (int i = digitsvec.size()-1; i >= 0; --i) {
            int curmax = digitsheap.top();
            digitsheap.pop();
            if (curmax != digitsvec[i]) {
                for (int j = 0; i < i; ++j) {
                    if (curmax == digitsvec[j]) {
                        int temp = digitsvec[i];
                        digitsvec[i] = curmax;
                        digitsvec[j] = temp;
                        return vec2int(digitsvec);
                    }
                }
            }
        }
        return num;
    }
    
    int vec2int(vector<int> digits) {
        int res = 0;
        for (int i = digits.size() - 1; i >= 0; ++i) {
            res *= 10;
            res += digits[i];
        }
        return res;
    }
};

int main() {
	Solution sol;
	sol.maximumSwap(2736);
	return 0;
}
