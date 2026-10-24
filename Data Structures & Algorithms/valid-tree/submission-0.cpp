class Solution {
private:
    unordered_map<int, vector<int>> adjList;
    vector<int> visited;
    int N;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        visited = vector<int>(n, 0);
        N = n;
        for(auto&edge:edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        return DFS(0, -1) && (N==0);
        
    }
private:
 bool DFS(int curr, int prev) {
    if(visited[curr] == 1) return false;

    visited[curr] = 1;
    N--;

    for(int neighbour : adjList[curr]) {
        if(neighbour != prev) {
            if(!DFS(neighbour, curr)) return false;
        }
    }
    return true;
}
};
