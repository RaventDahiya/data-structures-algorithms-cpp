class Solution {
private:
    vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src){
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [dis,node] = pq.top(); pq.pop();
            if(dis > dist[node]) continue;
            for(auto [nbr,wt] : adj[node]){
                if(dis + wt < dist[nbr]){
                    dist[nbr] = dis + wt;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        return dist;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        for(int i=0;i<n;i++){
            dist.push_back(dijkstra(n,adj,i));
        }
        
        int miniCities = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++){
            int citiesCanReach = 0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j] <= distanceThreshold) citiesCanReach++;
            }
            if(citiesCanReach <= miniCities){
                miniCities = citiesCanReach;
                ans = i;
            }
        }
        return ans;
    }
};