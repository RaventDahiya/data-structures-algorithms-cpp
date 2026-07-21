class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        queue<int>q;
        
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            
            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        
        if(ans.size()<numCourses) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};