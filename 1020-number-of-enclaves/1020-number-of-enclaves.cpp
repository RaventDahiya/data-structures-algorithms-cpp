class Solution {
public:
    int x[4] = {0, -1, 0, 1};
    int y[4] = {-1, 0, 1, 0};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis,int& n, int& m) {
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int ni = i + x[k];
            int nj = j + y[k];
            if (ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] == 1 && !vis[ni][nj]) {
                dfs(ni, nj, grid, vis, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis, n, m);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, grid, vis, n, m);
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, grid, vis, n, m);
            }
            if (grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                dfs(n - 1, i, grid, vis, n, m);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};