#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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
        for (int i = 0; i <= n; i++) {
            cout << i << " -> {";
            for (auto j : adjList[i]) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }

    void bfs(int n) {
        unordered_map<int, bool> visited;
        for (int src = 0; src <= n; src++) {
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
};

int main() {
    Graph g;
    // Edge u->v with weight and direction
    g.addEdge(0, 2, 1, 1);
    g.addEdge(0, 5, 1, 1);
    g.addEdge(0, 3, 1, 1);
    g.addEdge(2, 5, 1, 1);
    g.addEdge(5, 6, 1, 1);
    g.addEdge(5, 4, 1, 1);
    g.addEdge(4, 1, 1, 1);
    // Removed duplicate edge (4, 1)
    int n = 6; // number of nodes (assuming nodes labeled 0 to 6)
    g.printAdjList(n);

    cout << "BFS Traversal starting from node 0:" << endl;
    g.bfs(n);

    cout << "\nDFS Traversal starting from node 0:" << endl;
    g.dfs(n);
    return 0;
}
