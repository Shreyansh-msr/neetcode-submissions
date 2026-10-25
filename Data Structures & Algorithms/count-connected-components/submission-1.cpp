class Solution {
private:
unordered_map<int, vector<int>> adjList;
vector<int> visited;
public:
int countComponents(int n, vector<vector<int>>& edges) {
visited = vector<int>(n, -1); // marking all the nodes as not visited initially.
// build the adjacency list fot undirected graoh

for(auto& edge : edges) {
adjList[edge[0]].push_back(edge[1]);
adjList[edge[1]].push_back(edge[0]);
}
int label = 0;
for(int i=0; i<n; i++) {
if(!dfs(i, label)) {
label++;
}
}
return label;
}
private:
bool dfs(int i, int label) {
if(visited[i] != -1) return true;

visited[i] = label;
for(int nei : adjList[i]) {
dfs(nei, label);
}
return false;
}

}; 