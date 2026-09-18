class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // greedy : prioritize sheduling the task with highest remaining frequency.
        // find the frequency of every task
        vector<int> freq(26,0);
        for(char c: tasks) freq[c - 'A']++;

        // add tasks to heap based on their frequency;

        auto highFreqMaxOperator = [&freq](char a, char b){
            // returning true means first parameter has lower priority;
            return  freq[a - 'A'] < freq[b - 'A'];
        };

        priority_queue <char, vector<char>, decltype(highFreqMaxOperator)> heap(highFreqMaxOperator);

        for(int i=0; i<26; i++){
            if(freq[i] > 0) heap.push('A' + i);
        }

        int time = 0;
        queue<pair<char, int>> waitQueue; //use a queue to keep track of tasks that are on cooldown, this is not a stck, obvious !!


        // keep running untill all the tasks are completed.
        while(!heap.empty() || !waitQueue.empty()) {

            time++; // corresponding to the new cpu cycle 

            if(!heap.empty()) {
                char curr = heap.top();
                heap.pop();
                freq[curr -'A']--;

                if(freq[curr-'A']>0) waitQueue.push({curr, time+n});
            }

            if(!waitQueue.empty() && waitQueue.front().second == time) {
                heap.push(waitQueue.front().first);
                waitQueue.pop();
            }
        
        }
        
        return time;
        
    }
};
