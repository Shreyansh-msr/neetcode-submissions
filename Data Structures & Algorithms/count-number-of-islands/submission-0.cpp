class Solution {
private:
    int rows, cols;
    vector<vector<int>> seen;

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        rows = grid.size();
        cols = grid[0].size();
        seen = vector<vector<int>>(rows, vector<int>(cols, 0));

        int n = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && seen[i][j] == 0 ) {
                    streatch(i, j, grid);
                    n++;
                }
            }
        }
        return n;
    }
    void streatch(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({i,j});
        seen[i][j] = 1; 
        while(!q.empty()) {
            
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            vector<pair<int, int>> dirs = {
                {-1, 0},
                {0, -1},
                {0, 1},
                {1, 0}
            }; 

            for(auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && seen[nr][nc] == 0) {
                    q.push({nr, nc});
                    seen[nr][nc] = 1;
                }
            }
        }
    }
};