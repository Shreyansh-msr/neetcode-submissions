class Solution {
private:
    const int INF = 2147483647; 
    int rows;
    int cols;


public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        queue<pair<int,int>> q;
        // add all the treasure boxes in a queue
        for(int i = 0; i < rows; i++) for(int j = 0; j < cols; j++) if(grid[i][j] == 0)  q.push({i,j});
        
        vector<vector<int>> dirs = {
            {-1,0},
            {0,-1},
            {0,1},
            {1,0}
        };
        // multisourceBFS

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto & dir: dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];
                if(nr>=0 && nc >=0 && nr<rows && nc <cols && grid[nr][nc] == INF) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        
                
            
        
    }

    
};