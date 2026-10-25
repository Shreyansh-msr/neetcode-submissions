class Solution {
private:
    unordered_map<int, vector<int>> adjList;
    vector<bool> visited;

    void bfs(int startNode) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true; 

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adjList[node]) {
                if (!visited[nei]) {
                    visited[nei] = true; 
                    q.push(nei);
                }
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i); // Fixed: Changed from dfs(i) to bfs(i)
            }
        }

        return count;
    }
};