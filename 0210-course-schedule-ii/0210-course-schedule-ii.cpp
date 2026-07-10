class Solution {
public:
    vector<int> topoSortBFS(unordered_map<int, list<int>>& adjList, int n) {
        vector<int> topo;
        vector<int> indegree(n, 0);
        queue<int> q;
        for (auto p : adjList) {
            int u = p.first;
            for (auto v : p.second) {
                indegree[v]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);

            for (auto nbr : adjList[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if(topo.size() == n){
            return topo;
        }
        return {};
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;

        for (auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
        }
        return topoSortBFS(adjList, n);
        
    }
};
