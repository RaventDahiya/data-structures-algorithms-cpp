#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// DFS for adjacency list
void dfs(const vector<vector<int>>& adj, vector<bool>& visited, int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(adj, visited, v);
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;
    bfs(adj, start);

    cout << "Enter the starting node for DFS: ";
    cin >> start;
    vector<bool> visited(n, false);
    cout << "DFS Traversal starting from node " << start << ": ";
    dfs(adj, visited, start);
    cout << endl;

    return 0;
}
