class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.assign(n, vector<int>(n, 0));
        results.clear();
        
        // Initialize vectors instead of maps, pre-allocating exact sizes.
        col_attacks.assign(n, 0);
        pos_diagonals.assign(2 * n - 1, 0);
        neg_diagonals.assign(2 * n - 1, 0);
        
        // Start backtracking row-by-row
        backtrack(0); 
        
        return results;
    }

private:
    int n;
    vector<vector<int>> board; 
    vector<vector<string>> results;
    
    // Arrays (vectors) are drastically faster than maps
    vector<int> col_attacks;
    vector<int> pos_diagonals; 
    vector<int> neg_diagonals; 

    // Row-by-row backtrack (drops 'j', drops queens_placed count)
    void backtrack(int i) {
        if (i == n) {
            vector<string> current_solution;
            for (int r = 0; r < n; ++r) {
                string row_str = "";
                for (int c = 0; c < n; ++c) {
                    row_str += (board[r][c] == 1) ? 'Q' : '.';
                }
                current_solution.push_back(row_str);
            }
            results.push_back(current_solution);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (is_safe(i, j)) { 
                update_state(i, j, 1);
                
                backtrack(i + 1); // jump to next row
                
                update_state(i, j, -1); 
            }
        }
    }

    void update_state(int i, int j, int delta) {
        col_attacks[j] += delta;
        pos_diagonals[i + j] += delta;
        
        // Shift negative diagonal by (n - 1) to avoid negative array indices
        neg_diagonals[i - j + (n - 1)] += delta;
        
        if (delta == 1) {
            board[i][j] = 1; 
        } else if (delta == -1) {
            board[i][j] = 0;
        }
    }
    
    bool is_safe(int i, int j) {
        return col_attacks[j] == 0 && 
               pos_diagonals[i + j] == 0 && 
               neg_diagonals[i - j + (n - 1)] == 0;
    }
};