class Solution {
private:
    vector<int> parent;

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n, -1); // initially all the nodes are their own parent
        for(auto&edge:edges) {
            unite(edge[0], edge[1]);
        }
        int count=0;
        for(int i=0; i<n ; i++) {
            if(parent[i] < 0) count ++;
        }
        return count;
    }
private:
    // return the root of n (leader of the set)
    int find(int n) {
        if(parent[n] < 0) return n;
        // path compression
        else return parent[n] = find(parent[n]);
    }

    void unite(int n1, int n2) {
        int root_n1 = find(n1); 
        int root_n2 = find(n2);
        if (root_n1 == root_n2) return; // same index
        if(parent[root_n1] <= parent[root_n2]) {
            parent[root_n1] += parent[root_n2]; 
            parent[root_n2] = root_n1;          
        }
        else {
            parent[root_n2] += parent[root_n1]; 
            parent[root_n1] = root_n2;
        }
        
    }

};