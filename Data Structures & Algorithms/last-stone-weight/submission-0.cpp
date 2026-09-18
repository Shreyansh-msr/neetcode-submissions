class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;

        for(int weight : stones){
            maxHeap.push(weight);
        }

        while(true){
            if(maxHeap.empty()) return 0;
            if(maxHeap.size() < 2) return maxHeap.top();

            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if(x != y) {
                maxHeap.push(abs(x-y));
            }
        }
    }
};
