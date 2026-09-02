class Solution {
public:
    vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& adj) {
        int n = adj.size();

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, wt] : adj[u]) {
                int newDist = d + wt;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int> canReach(n);
        for (int i = 0; i < n; i++) {
            vector<int> dist = dijkstra(i, adj);
            for (int u = 0; u < n; u++) {
                if (u != i && dist[u] <= distanceThreshold) {
                    canReach[u]++;
                }
            }
        }
        int ans = -1;
        int minCitesReaches = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (canReach[i] <= minCitesReaches) {
                minCitesReaches = canReach[i];
                ans = i;
            }
        }
        return ans;
    }
};