class Solution {
private:
    unordered_map<int, vector<int>> adjacencyList;
    unordered_set<int> seen;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjacencyList.clear();
        seen.clear();

        for (const auto& pair : prerequisites) {
            adjacencyList[pair[0]].push_back(pair[1]);
        }

        for (int crs = 0; crs < numCourses; crs++) {
            if (dfs(crs)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int crs) {
        if (seen.count(crs)) {
            return true; // cycle
        }
        if (adjacencyList[crs].empty()) {
            return false; // no cycle
        }

        seen.insert(crs);
        for (int preReq : adjacencyList[crs]) { 
            if (dfs(preReq)) {
                return true;
            }
        }
        seen.erase(crs);
        adjacencyList[crs].clear();
        return false;
    }
};