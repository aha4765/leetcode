class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int xdim = board.size();
        int ydim = board[0].size();
        vector<vector<bool>> visited(xdim, vector<bool>(ydim, false));
        for (int i = 0; i < xdim; ++i) {
            for (int j = 0; j < ydim; ++j) {
                if (existHelper(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool existHelper(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int x, int y, int index) {
        if (word[index] != board[x][y]) {
            return false;
        }
        else {
            visited[x][y] = true;
            if (index == (word.size()-1)) {
                return true;
            }
            else if ((x-1 >= 0) && (visited[x-1][y] == false) && (existHelper(board, word, visited, x-1, y, index+1))) {
                return true;
            }
            else if ((x+1 < board.size()) && (visited[x+1][y] == false) && (existHelper(board, word, visited, x+1, y, index+1))) {
                return true;
            }
            else if ((y-1 >= 0) && (visited[x][y-1] == false) && (existHelper(board, word, visited, x, y-1, index+1))) {
                return true;
            }
            else if ((y+1 < board[0].size()) && (visited[x][y+1] == false) && (existHelper(board, word, visited, x, y+1, index+1))) {
                return true;
            }
            else {
                visited[x][y] = false;
                return false;
            }
        }
    }
};
