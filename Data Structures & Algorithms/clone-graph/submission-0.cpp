class Solution {
private:
    unordered_map<Node*, Node*> seen;
public:
    Node* cloneGraph(Node* node) {

        if (!node) return nullptr;
        if (seen.find(node) != seen.end()) {
            return seen[node];
        }
        Node* root = new Node(node->val);
        seen[node] = root;
        for (Node* neighbor : node->neighbors) {
            root->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return root;
    }
};