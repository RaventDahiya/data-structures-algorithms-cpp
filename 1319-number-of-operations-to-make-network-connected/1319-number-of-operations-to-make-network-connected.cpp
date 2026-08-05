class DisjointSet {
    vector<int> rank, parent,size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1,1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already in same component
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already in same component
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();
        DisjointSet ds(n);
        int edgesUsed = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) != ds.findUPar(v)){
                edgesUsed++;
                ds.unionBySize(u,v);
            }
        }
        int edgesLeft = totalEdges - edgesUsed;

        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i) count++;
        }
        if(count - 1 <= edgesLeft) return count-1;
        return -1;

    }
};