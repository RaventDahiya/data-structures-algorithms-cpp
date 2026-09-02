class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto arr : times){
            adj[arr[0]].push_back({arr[1],arr[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>>pq;
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;
            for(auto& [v,wt] : adj[u]){
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};