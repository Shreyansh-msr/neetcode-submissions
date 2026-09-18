/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node *tail = head;
        Node dummy_ = Node(0); 
        Node *tail_ = &dummy_; 
        unordered_map<Node*, Node*> map= {};

        while(tail){
            tail_ -> next = new Node(tail->val);
            tail_ = tail_->next;
            map[tail] = tail_;
            tail = tail->next;
        }
        Node *head_ = dummy_.next;

        tail = head; //restart
        tail_ = head_;
        while(tail_){
            tail_ -> random = map[tail -> random];
            tail_ = tail_->next;
            tail = tail->next;
        }
        return head_;
    }
};
