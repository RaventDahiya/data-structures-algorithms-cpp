class Solution {
public:
    bool dfs(int node,vector<vector<int>>& g,vector<int>&state){
        if(state[node]==2) return true; //already processed
        if(state[node]==3) return false;//already processed
        if(state[node]==1) return false; //cycle found
        state[node] = 1;
        for(auto nbr:g[node]){
            if(!dfs(nbr,g,state)){
                state[node] = 3;
                return false;
            }
        }
        state[node] = 2;
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int>state(n,0); //0:unvis 1:currInPath 2:safe 3:unsafe
        vector<int>safeNodes;
        for(int i=0;i<n;i++){
            if(dfs(i,g,state)) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};