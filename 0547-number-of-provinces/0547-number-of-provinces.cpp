class Solution {
public:
    void dfs(int node,vector<vector<int>>&isConnected,vector<bool>&vis){
        vis[node] = true;
        for(int nbr=0;nbr<isConnected.size();nbr++){
            if(!vis[nbr] && isConnected[node][nbr]==1) dfs(nbr,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        int ans = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};