class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int n_fresh = 0;
        queue<pair<int, int>> q;

        int n_minutes = 0;

        for(int i=0; i<ROWS;i++) {
            for(int j=0;j<COLS;j++) {
                if(grid[i][j] == 1) n_fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};

        while(!q.empty() && n_fresh > 0) {
            int size = q.size();

            for(int k=0; k<size; k++){
                auto[i,j] = q.front();
                q.pop();

                for(auto&dir:dirs) {
                    int nr = i + dir[0];
                    int nc = j + dir[1];

                    if( nr>=0 && nc>= 0 && nr<ROWS && nc<COLS && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        n_fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            
            n_minutes++; 
        }
        
        return (n_fresh == 0) ? n_minutes : -1;
    }
};