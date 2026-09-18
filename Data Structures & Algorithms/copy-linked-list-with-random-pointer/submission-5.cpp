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
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
       if(!head) return nullptr; //end of the linked list
        if(map.count(head)) return map[head];
        // create a new node / deep copy
        Node *newNode = new Node(head->val);
        map[head] = newNode;
        // make links with new addresses
        newNode -> next = copyRandomList(head->next);
        newNode -> random = copyRandomList(head->random);
        return newNode;
    }
};
