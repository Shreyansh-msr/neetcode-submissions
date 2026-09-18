class MedianFinder {
private:
    private:
    // Max heap
    priority_queue<int> lHeap; 
    // Min heap
    priority_queue<int, vector<int>, greater<int>> rHeap;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lHeap.empty() || num <= lHeap.top()) lHeap.push(num);
        else rHeap.push(num);

        int ls = lHeap.size();
        int rs = rHeap.size();

        while(ls > rs + 1){
            rHeap.push(lHeap.top());
            lHeap.pop();
            ls--;
            rs++;
        }
        while(rs > ls + 1){
            lHeap.push(rHeap.top());
            rHeap.pop();
            ls++;
            rs--;
        }
        
    }
    
    double findMedian() {

        int ls = lHeap.size();
        int rs = rHeap.size();

        if(ls == rs) return (lHeap.top() + rHeap.top()) / (double)2;
        // if there are odd number of elements 
        else if( ls > rs) return lHeap.top();
        else return rHeap.top();
    }
};
