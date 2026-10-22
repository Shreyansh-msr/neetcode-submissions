class Solution {
private:
    int rows;
    int cols;
    vector<vector<bool>> seen;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        seen = vector<vector<bool>>(rows, vector<bool>(cols, false));

        int area = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if( grid[i][j] == 1 && !seen[i][j]) {
                    area =  max(area, streatch(i,j, grid));
                }
            }
        }
        return area;
    }

    int streatch(int i, int j, vector<vector<int>>&grid) {
        queue<pair<int, int>> q;
        q.push({i,j});
        seen[i][j] = true;
        vector<pair<int, int>> dirs = {
            {-1,0},
            {0,-1},
            {1,0},
            {0,1}
        };

        int area = 0;
        while(!q.empty()) {
            int f = q.front().first;
            int s = q.front().second;
            q.pop();
            area++;

            for(auto dir : dirs) {
                int r =  f + dir.first;
                int c = s + dir.second;

                if( r>=0 && c>=0 && r<rows && c<cols && grid[r][c] == 1 && !seen[r][c]) {
                    q.push({r,c});
                    seen[r][c] = true;
                }
            }
        }
        return area;
    }
};
