class Solution {
private:
    int rows;
    int cols;
    vector<vector<bool>> flag; 

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        rows = board.size();
        cols = board[0].size();
        flag = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O' && !flag[i][0]) mark_flag(i, 0, board);
            if (board[i][cols - 1] == 'O' && !flag[i][cols - 1]) mark_flag(i, cols - 1, board);
        }

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O' && !flag[0][j]) mark_flag(0, j, board);
            if (board[rows - 1][j] == 'O' && !flag[rows - 1][j]) mark_flag(rows - 1, j, board);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && !flag[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
private:
    void mark_flag(int i, int j, vector<vector<char>>& board) {
        vector<pair<int, int>> dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
        flag[i][j] = true;
        
        for (auto dir : dirs) {
            int r = i + dir.first;
            int c = j + dir.second;
            
            if (r >= 0 && r < rows && c >= 0 && c < cols && !flag[r][c] && board[r][c] == 'O') {
                mark_flag(r, c, board);
            }
        }
    }
};