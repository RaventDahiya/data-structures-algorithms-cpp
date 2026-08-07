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
        int n = 0;
        int m = 0;
        for(auto it : stones){
            int i = it[0];
            int j = it[1];
            n = max(n,i);
            m = max(m,j);
        }
        DisjointSet ds(n+m+1);
        unordered_set<int>st;
        for(auto it : stones){
            int i = it[0];
            int j = it[1] + n + 1;
            ds.unionBySize(i,j);
            st.insert(i);
            st.insert(j);
        }
        int compCount = 0;
        for(auto it : st){
            if( it == ds.findUPar(it)) compCount++;
        }
        return stones.size() - compCount;
    }
};