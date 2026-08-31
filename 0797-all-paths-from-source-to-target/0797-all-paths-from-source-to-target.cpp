class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&currPath,vector<vector<int>>&allPaths,vector<bool>&vis,int n){
        vis[node] = true;
        currPath.push_back(node);
        if(node==n-1) allPaths.push_back(currPath);

        for(auto& nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr,adj,currPath,allPaths,vis,n);
            }
        }
        vis[node] = false;
        currPath.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>>allPaths;
        vector<int>currPath;
        vector<bool>vis(n,false);
        dfs(0,adj,currPath,allPaths,vis,n);
        return allPaths;
    }
};