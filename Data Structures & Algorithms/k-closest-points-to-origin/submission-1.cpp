class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // lambda operator
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
            int dA = (a.first*a.first) + (a.second*a.second);
            int dB = (b.first*b.first) + (b.second*b.second);
            // return true if a is below b in heap, max heap
            return dA < dB;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

        for(int i=0; i<points.size(); i++)
        {
            pq.push({points[i][0], points[i][1]});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> result;
        while(!pq.empty()) {
            result.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return result;
    }
};
