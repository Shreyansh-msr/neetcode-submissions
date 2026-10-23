class Solution {
private:
    int ROWS;
    int COLS;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < ROWS; i++) for(int j = 0; j < COLS; j++) {
                if(canFlow(i, j, heights)) res.push_back({i, j});
        }
        return res;
    }
    
    bool canFlow(int i, int j, vector<vector<int>>& heights) {
        bool foundPacific = false, foundAtlantic = false;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        queue<pair<int, int>> q;
        
        q.push({i, j});
        visited[i][j] = true;
        
        while(!q.empty()) {
            auto[r, c] = q.front();
            q.pop();
            for(auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr < 0 || nc < 0) foundPacific = true;
                if(nr >= ROWS || nc >= COLS) foundAtlantic = true;

                if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && !visited[nr][nc] && heights[nr][nc] <= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            if (foundPacific && foundAtlantic) return true; 
        }
        return foundPacific && foundAtlantic;
    }
};