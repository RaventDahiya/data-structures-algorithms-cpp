class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<tuple<int, int, int>> q;
        q.push({0,src,0}); //hope , node , dis

        while (!q.empty()) {
            auto [hops,node, dis] = q.front(); q.pop();
            if (hops > k) continue;

            for (auto [nbr, wt] : adj[node]) {
                if (dis + wt < dist[nbr] && hops <=k) {
                    dist[nbr] = dis + wt;
                    q.push({hops+1,nbr,dist[nbr]});
                }
            }
        }

        return dist[dst]==INT_MAX ? -1 :dist[dst];
    }
};