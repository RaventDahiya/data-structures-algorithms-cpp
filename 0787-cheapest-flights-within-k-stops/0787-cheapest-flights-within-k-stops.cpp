class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<tuple<int,int,int>>pq;
        pq.push({0,src,0}); //hope,node,dis
        
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        while(!pq.empty()){
            auto [hops,u,d] = pq.front(); pq.pop();
            if(hops > k) continue;

            for(auto [v,wt] : adj[u]){
                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    pq.push({hops+1,v,dist[v]});
                }
            }
        }
        return dist[dst]!=INT_MAX ? dist[dst] : -1;
    }
};