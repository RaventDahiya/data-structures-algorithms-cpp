class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int>indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto nbr : graph[i]){
                adjRev[nbr].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        vector<int>safeNodes;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front(); q.pop();
            safeNodes.push_back(node);
            for(auto nbr : adjRev[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};