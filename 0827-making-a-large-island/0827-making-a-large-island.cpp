class DisjointSet {
public:
    vector<int> rank, parent,size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int u = i*n + j;
                    for(int dir=0;dir<4;dir++){
                        int newRow = i + dx[dir];
                        int newCol = j + dy[dir];
                        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n && grid[newRow][newCol]==1){
                            int v = newRow*n+newCol;
                            if(ds.findUPar(u)!=ds.findUPar(v)){
                                ds.unionBySize(u,v);
                            }
                        }
                    }
                }
            }
        }
        int maxSizeIsland = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st; //unique UPar 
                    for(int dir=0;dir<4;dir++){
                        int newRow = i + dx[dir];
                        int newCol = j + dy[dir];
                        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n && grid[newRow][newCol]==1){
                            int node = newRow*n+newCol;
                            st.insert(ds.findUPar(node));
                        }
                    }
                    int size = 1;
                    for(auto node : st){
                        size += ds.size[node];
                    }
                    maxSizeIsland = max(maxSizeIsland,size);
                }
            }
        }
        if(maxSizeIsland == INT_MIN) return n*n;
        return maxSizeIsland;
    }
};