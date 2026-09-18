#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int ROWS, COLS;

public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        
      
        vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));


        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (backTrack(i, j, 0, board, visit, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backTrack(int i, int j, int index, const vector<vector<char>>& board, vector<vector<int>>& visit, const string& word) {

        if (index == word.size()) {
            return true;
        }

   
        if (i < 0 || i >= ROWS || j < 0 || j >= COLS || visit[i][j] == 1 || board[i][j] != word[index]) {
            return false;
        }

        
        visit[i][j] = 1;

  
        bool found = backTrack(i + 1, j, index + 1, board, visit, word) || 
                     backTrack(i, j + 1, index + 1, board, visit, word) || 
                     backTrack(i - 1, j, index + 1, board, visit, word) || 
                     backTrack(i, j - 1, index + 1, board, visit, word);


        visit[i][j] = 0;

        return found;
    }
};