class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathVis,vector<int>&safe){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto nbr : graph[node]){
            if(!vis[nbr]){
                if(dfs(nbr,graph,vis,pathVis,safe)==true){
                    safe[node] = 0;
                    return true;
                }
            }
            else if(pathVis[nbr]){
                safe[node] = 0;
                return true;
            }
        }
        safe[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>safe(n,0);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,safe);
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};