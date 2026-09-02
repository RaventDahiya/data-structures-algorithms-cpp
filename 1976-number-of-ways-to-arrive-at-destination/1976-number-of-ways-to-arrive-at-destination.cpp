class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        const int MOD = 1e9 + 7;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto [v, wt] : adj[u]) {

                long long newDis = dist[u] + wt;

                if(newDis < dist[v]) {

                    dist[v] = newDis;
                    ways[v] = ways[u];

                    pq.push({dist[v], v});
                }
                else if(newDis == dist[v]) {

                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};