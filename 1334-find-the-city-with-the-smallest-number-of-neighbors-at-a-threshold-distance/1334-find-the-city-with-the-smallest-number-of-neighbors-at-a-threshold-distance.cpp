class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for (int h = 0; h < n; h++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (dist[u][h] != INT_MAX && dist[h][v] != INT_MAX) {
                        dist[u][v] = min(dist[u][v], dist[u][h] + dist[h][v]);
                    }
                }
            }
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