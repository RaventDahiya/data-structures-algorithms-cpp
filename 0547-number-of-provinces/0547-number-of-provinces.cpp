class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node] = true;
        for(int nbr:adj[node]){
            if(!vis[nbr]) dfs(nbr,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};