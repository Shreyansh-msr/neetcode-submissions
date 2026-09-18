struct ListNode{
    int key;
    int value;
    ListNode * prev;
    ListNode * next;

    ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {};
};
class LRUCache {
    private:
    int size;
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;

    // we will be using dummy nodes to eleminate the need of edge cases

    void unlinkNode(ListNode* node) {
        // This function will attach the nodes previous node to the next node, unlinking the node from the chain
        node -> prev -> next = node -> next;
        node ->next -> prev = node -> prev;
    }

    void insertAtRight(ListNode* node) {
        ListNode* Last = right -> prev; //right is a dummy node
        Last -> next = node;
        node -> prev = Last;
        node -> next = right;
        right -> prev = node;
    }



    public:
    //constructor
    LRUCache(int cap){
        size = cap;
        left = new ListNode(-1,-1); //dummy node before start of actual list
        right = new ListNode(-1,-1); //dummy node after the end of actual list
        left -> next = right;
        right -> prev = left;
    }

    //destructor
    // Clean up memory to avoid leaks
    ~LRUCache() {
        ListNode* curr = left;
        while (curr != nullptr) {
           ListNode* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int key) {
        if(cache.find(key) != cache.end()){
            ListNode *MRU = cache[key];

            // update the last node to the most recently used node
            unlinkNode(MRU);
            insertAtRight(MRU);

            return MRU->value;
        }
        return -1;
    }

    void put(int key, int value) {
        //if it exists previuously, update it and make it MRU
        if(cache.find(key) != cache.end()) {
            cache[key] -> value = value;
            unlinkNode(cache[key]);
            insertAtRight(cache[key]);
        } else {
            // if the capacity is full remove LRU
            if(cache.size() == size){
                ListNode *LRU = left->next;
                cache.erase(LRU->key);
                unlinkNode(LRU);
                delete LRU;
            }
            // insert
            cache[key] = new ListNode(key, value);
            insertAtRight(cache[key]);
        }
    }
};
