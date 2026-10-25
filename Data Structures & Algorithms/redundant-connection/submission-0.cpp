class Solution {
vector<int> parent;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent = vector<int>(edges.size()+1, -1);
        for(auto&edge:edges) {
            if(unite(edge[0], edge[1])) return edge;
        }
        return {};
    }

    int find(int node) {
        if(parent[node] < 0) return node;
        else return parent[node] = find(parent[node]); // compression
    }

    bool unite(int n1, int n2) {
        int r1 = find(n1);
        int r2 = find(n2);

        if(r1 == r2) return true;

        if( parent[r1] <= parent[r2] ) {
            parent[r1] += parent[r2];
            parent[r2] = r1;
        }
        else {
            parent[r2] += parent[r1];
            parent[r1] = r2;
        }
        return false;
    }
};
