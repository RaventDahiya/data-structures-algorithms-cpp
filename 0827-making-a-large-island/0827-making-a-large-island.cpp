class DisjointSet {
    
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
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
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
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
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int x[] = {0, -1, 0, 1};
        int y[] = {-1, 0, 1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int dsIndex = i * n + j;
                    for (int dir = 0; dir < 4; dir++) {
                        int newX = i + x[dir];
                        int newY = j + y[dir];
                        if (newX >= 0 && newY >= 0 && newX < n && newY < n && grid[newX][newY]) {
                            int nbrDsIndex = newX * n + newY;
                            ds.unionBySize(nbrDsIndex,dsIndex);
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int dsIndex = i * n + j;
                    int count = 1;
                    unordered_set<int>st;
                    for (int dir = 0; dir < 4; dir++) {
                        int newX = i + x[dir];
                        int newY = j + y[dir];
                        if (newX >= 0 && newY >= 0 && newX < n && newY < n && grid[newX][newY]) {
                            int nbrDsIndex = newX * n + newY;
                            st.insert(ds.findUPar(nbrDsIndex));
                        }
                    }
                    for(auto it : st){
                        count += ds.size[it];
                    }
                    ans = max(ans,count);
                }
            }
        }
        return ans!=INT_MIN ? ans : n*n;
    }
};