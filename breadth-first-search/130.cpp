// dfs works, but be careful of stack overflow

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int l1 = board.size();
        int l2 = board[0].size();
        for (int i = 0; i < l1; ++i) {
            if (board[i][0] == 'O') {
                findobj(i, 0, board);
            }
            if (l2 >= 1) {
                if (board[i][l2-1] == 'O') {
                    findobj(i, l2-1, board);
                }
            }
        }
        for (int i = 0; i < l2; ++i) {
            if (board[0][i] == 'O') {
                findobj(0, i, board);
            }
            if (l1 >= 1) {
            if (board[l1-1][i] == 'O') {
                findobj(l1-1, i, board);
            }
            }
        }
        
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
    
    // try dfs first
    void findobj(int i, int j, vector<vector<char>>& board) {
        board[i][j] = 'A';
        if (i > 1) {
            if (board[i-1][j] == 'O') findobj(i-1, j, board);
        }
        if (i < (board.size() -1)) {
            if (board[i+1][j] == 'O') findobj(i+1, j, board);
        }
        if (j > 1) {
            if (board[i][j-1] == 'O') findobj(i, j-1, board);
        }
        if (j < (board[0].size()-1)) {
            if (board[i][j+1] == 'O') findobj(i, j+1, board);
        }
        return;
    }
};
