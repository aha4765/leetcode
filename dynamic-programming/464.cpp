class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) {
            return false;
        }
        vector<bool> state(maxChoosableInteger, false);
        return windfs(state, desiredTotal);
    }
    
    // can the one who plays first in this state win?
    // he can win as long as one choice leads to win
    // if total <= 0, it means the player plays first has already loses the game
    bool windfs(vector<bool> state, int total) {
        if (total <= 0) {
            return false;
        }
        int key = vectoint(state);
        if (memmap.count(key) == 0) {
            for (int i = 0; i < state.size(); ++i) {
                if (state[i] == false) {
                    state[i] = true;
                    if (!windfs(state, total-i-1)) {
                        memmap[key] = true;
                        return true;
                    }
                    state[i] = false;
                }
            }
            memmap[key] = false;
            return false;
        }
        else {
            return memmap[key];
        }
    }

private:
    unordered_map<int, bool> memmap;
    int vectoint(const vector<bool>& state) {
        int res = 0;
        for (int i = 0; i < state.size(); ++i) {
            res = res << 1;
            if (state[i]) {
                res += 1;
            }
        }
        return res;
    }
};
