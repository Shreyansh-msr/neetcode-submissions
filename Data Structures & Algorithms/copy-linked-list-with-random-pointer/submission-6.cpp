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
       if(!head) return nullptr;
        Node dummy = Node(0);
        Node *tail = &dummy;
        unordered_map<Node*, Node*> map;
        map[nullptr] = nullptr;

        while(head){
            if(map.count(head)) {
                tail -> next = map[head];
            } else {
                tail -> next = new Node(head->val);
                map[head] = tail->next; //update the map
            }
            tail = tail->next;
            if(map.count(head->random)) {
                tail -> random = map[head->random];
            } else {
                tail -> random = new Node( head -> random -> val);
                map[head->random] = tail -> random;
            }
            head = head->next;
        }
        return dummy.next;
    }
};
