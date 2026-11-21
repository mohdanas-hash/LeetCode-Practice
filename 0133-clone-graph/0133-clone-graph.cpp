/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> clones;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // If this node has already been cloned, return its clone immediately
        if (clones.find(node) != clones.end()) {
            return clones[node];
        }

        // Create the clone node and register it before recursing on neighbors
        Node* copy = new Node(node->val);
        clones[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};