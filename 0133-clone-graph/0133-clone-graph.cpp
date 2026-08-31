class Solution {
    // Map to keep track of processed nodes
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If we have already created a clone for this node, return it
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create the clone for the current node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Recursively clone the neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
