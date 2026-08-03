class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // {shortest distance, number of ways}
        vector<pair<long long, int>> dist(n, {LLONG_MAX, 0});

        dist[0] = {0, 1};

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node].first)
                continue;

            for (auto [nbr, wt] : adj[node]) {

                long long newDist = dis + wt;

                // Found a shorter path
                if (newDist < dist[nbr].first) {
                    dist[nbr].first = newDist;
                    dist[nbr].second = dist[node].second;

                    pq.push({newDist, nbr});
                }

                // Found another shortest path
                else if (newDist == dist[nbr].first) {
                    dist[nbr].second =
                        (dist[nbr].second + dist[node].second) % MOD;
                }
            }
        }

        return dist[n - 1].second;
    }
};