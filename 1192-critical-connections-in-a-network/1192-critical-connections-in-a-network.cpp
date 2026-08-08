class Solution {
public:
    void findBridge(int src,int par,int time,vector<int>&tin,vector<int>&mt,vector<int>&vis,vector<vector<int>>&adj,vector<vector<int>>&ans){
        vis[src] = 1;
        time++;
        tin[src] = time;
        mt[src] = time;
        for(auto nbr : adj[src]){
            if(nbr == par) continue;
            else if(!vis[nbr]){
                findBridge(nbr,src,time,tin,mt,vis,adj,ans);
                mt[src] = min(mt[src],mt[nbr]);
                if(mt[nbr] > tin[src]){
                    ans.push_back({src,nbr});
                }
            }else{
                mt[src] = min(mt[src],mt[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>tin(n,0);
        vector<int>mt(n,0);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int time = 0;
                findBridge(i,-1,time,tin,mt,vis,adj,ans);
            }
        }
        return ans;
    }
};