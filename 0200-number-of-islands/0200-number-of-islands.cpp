class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {
        vis[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + x[dir];
                int newCol = col + y[dir];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int islandCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    islandCount++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return islandCount;
    }
};