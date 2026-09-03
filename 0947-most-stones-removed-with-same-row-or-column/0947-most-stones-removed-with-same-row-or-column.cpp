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
    int removeStones(vector<vector<int>>& stones) {
        int totalStones = stones.size();
        int n = 0;
        int m = 0;
        int comp = 0;
        
        for(auto it : stones){
            n = max(it[0],n);
            m = max(m,it[1]);
        }
        DisjointSet ds(n+m+1);
        unordered_map<int,int>stoneNodes;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = n + it[1] + 1;
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
            ds.unionBySize(nodeRow,nodeCol);
        }
        for(int i=0;i<n+m+1;i++){
            if(stoneNodes.count(i)){
                if(ds.findUPar(i)==i) comp++;
            }
        }
        return totalStones - comp;
    }
};