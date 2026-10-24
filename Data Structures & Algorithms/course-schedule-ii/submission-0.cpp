class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res; 
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for(auto& prereq : prerequisites) {
            indegree[prereq[0]]++;
            adjList[prereq[1]].push_back(prereq[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int crs = q.front();
            res.push_back(crs);
            q.pop();
            
            for(int nextCourse : adjList[crs]) {
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0) q.push(nextCourse);
            }
        }
        if (res.size() == numCourses) {
            return res;
        }
        return {}; 
    }
};