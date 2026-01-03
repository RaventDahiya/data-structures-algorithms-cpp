#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight = 1, int direction = 0) {
        // direction = 0 -> undirected
        // direction = 1 -> directed
        adjList[u].push_back({ v, weight });
        if (direction == 0) {
            adjList[v].push_back({ u, weight });
        }
    }

    void printAdjList(int n) {
        for (int i = 0; i < n; i++) {
            cout << i << " -> {";
            for (auto j : adjList[i]) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }

    void bfs(int n) {
        unordered_map<int, bool> visited;
        for (int src = 0; src < n; src++) {
            if (!visited[src]) {
                bfsUtil(src, visited);
            }
        }
    }

    void bfsUtil(int src, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    q.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }
    }

    void dfs(int n) {
        unordered_map<int, bool> visited;
        for (int src = 0; src <= n; src++) {
            if (!visited[src]) {
                dfsUtil(src, visited);
            }
        }
    }

    void dfsUtil(int node, unordered_map<int, bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                dfsUtil(neighbor.first, visited);
            }
        }
    }
    bool cycle_Detection_Undirected_Graph_BFS_helper(int n) {
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (cycle_Detection_Undirected_Graph_BFS(i, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool cycle_Detection_Undirected_Graph_BFS(int src, unordered_map<int, bool>& visited) {
        unordered_map<int, int> parent;

        parent[src] = -1;
        visited[src] = true;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int front = q.front(); q.pop();
            for (auto neighbor : adjList[front]) {
                if (!visited[neighbor.first]) {

                    q.push(neighbor.first);
                    visited[neighbor.first] = true;
                    parent[neighbor.first] = front;

                }
                else if (visited[neighbor.first] && neighbor.first != parent[front]) return true;

            }
        }
        return false;
    }

    bool cycle_Detection_undireted_graph_dfs_helper(int n) {
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (cycle_Detection_undirected_graph_dfs(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool cycle_Detection_undirected_graph_dfs(int node, unordered_map<int, bool>& visited, int parent) {
        visited[node] = true;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                if (cycle_Detection_undirected_graph_dfs(neighbor.first, visited, node)) {
                    return true;
                }
            }
            else if (visited[neighbor.first] && neighbor.first != parent) {
                return true;
            }
        }
        return false;
    }

    bool direted_graph_cycle_detection_dfs_helper(int n) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> inStack;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (directed_graph_cycle_detection_dfs(i, visited, inStack)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool directed_graph_cycle_detection_dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& inStack) {
        visited[node] = true;
        inStack[node] = true;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                if (directed_graph_cycle_detection_dfs(neighbor.first, visited, inStack)) {
                    return true;
                }
            }
            else if (inStack[neighbor.first]) {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }

    // Topological Sort using DFS
    void topologicalSortDFS(int node, unordered_map<int, bool>& visited, stack<int>& topoStack) {
        visited[node] = true;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                topologicalSortDFS(neighbor.first, visited, topoStack);
            }
        }
        topoStack.push(node);
    }

    vector<int> topologicalSort(int n) {
        unordered_map<int, bool> visited;
        stack<int> topoStack;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topologicalSortDFS(i, visited, topoStack);
            }
        }
        
        vector<int> result;
        while (!topoStack.empty()) {
            result.push_back(topoStack.top());
            topoStack.pop();
        }
        return result;
    }

    // Topological Sort using Kahn's Algorithm (BFS)
    vector<int> topologicalSortBFS(int n) {
        vector<int> indegree(n, 0);
        
        // Calculate indegree of all nodes
        for (int i = 0; i < n; i++) {
            for (auto neighbor : adjList[i]) {
                indegree[neighbor.first]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int front = q.front(); q.pop();
            result.push_back(front);
            
            for (auto neighbor : adjList[front]) {
                indegree[neighbor.first]--;
                if (indegree[neighbor.first] == 0) {
                    q.push(neighbor.first);
                }
            }
        }
        return result;
    }

    // Single Source Shortest Path in DAG using Topological Sort
    vector<int> shortestPathDAG(int src, int n) {
        // Step 1: Get topological order
        unordered_map<int, bool> visited;
        stack<int> topoStack;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topologicalSortDFS(i, visited, topoStack);
            }
        }
        
        // Step 2: Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // Step 3: Process nodes in topological order
        while (!topoStack.empty()) {
            int node = topoStack.top(); topoStack.pop();
            
            if (dist[node] != INT_MAX) {
                for (auto neighbor : adjList[node]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[node] + weight < dist[v]) {
                        dist[v] = dist[node] + weight;
                    }
                }
            }
        }
        
        return dist;
    }

    vector<int>dijkstra(int src, int n) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Min-heap priority queue
        set<pair<int, int>> st;
        st.insert({ 0, src }); // {distance, node}

        while (!st.empty()) {
            auto front = *(st.begin()); // Get the node with the smallest distance
            int node = front.second;
            int nodeDist = front.first;
            st.erase(st.begin()); // Remove it from the set

            for (auto neighbor : adjList[node]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (nodeDist + weight < dist[v]) {
                    // Update distance
                    auto result = st.find({ dist[v], v }); // Find the old distance entry
                    if (result != st.end()) {
                        st.erase(result);
                    }
                    dist[v] = nodeDist + weight; 
                    st.insert({ dist[v], v }); // Insert the updated distance
                }
            }
        }

        return dist;
    }
    
    vector<int>bellman_Ford(int src, int n) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax edges up to (n-1) times
        for (int i = 0; i < n - 1; i++) {
            for (auto edge : adjList) {
                int u = edge.first;
                for (auto neighbor : edge.second) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (auto edge : adjList) {
            int u = edge.first;
            for (auto neighbor : edge.second) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return {};
                }
            }
        }

        return dist;
    }


    vector<vector<int>> flaydWarshall(int n){
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances based on adjacency list
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0; // Distance to self is zero
            for (auto neighbor : adjList[i]) {
                dist[i][neighbor.first] = neighbor.second;
            }
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph g;
    // Edge u->v with weight and direction
    g.addEdge(0, 1, 1, 1);
    g.addEdge(0, 4, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(1, 3, 1, 1);
    g.addEdge(1, 4, 1, 1);
    g.addEdge(2, 3, 1, 1);
    g.addEdge(3, 4, 1, 1);
    g.addEdge(4, 1, 1, 1);
    // Removed duplicate edge (4, 1)
    int n = 5; // number of nodes (assuming nodes labeled 0 to 6)
    // g.printAdjList(n);

    // cout << "BFS Traversal starting from node 0:" << endl;
    // g.bfs(n);

    // cout << "\nDFS Traversal starting from node 0:" << endl;
    // g.dfs(n);

    // Cycle Detection in Undirected Graph using DFS
    // if (g.cycle_Detection_undireted_graph_dfs_helper(n)) {
    //     cout << "Cycle detected in the undirected graph using DFS." << endl;
    // }
    // else {
    //     cout << "No cycle detected in the undirected graph using DFS." << endl;
    // }

    // Cycle Detection in Directed Graph using DFS
    // if (g.direted_graph_cycle_detection_dfs_helper(n)) {
    //     cout << "Cycle detected in the directed graph using DFS." << endl;
    // }
    // else {
    //     cout << "No cycle detected in the directed graph using DFS." << endl;
    // }


    return 0;
}
