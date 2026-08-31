class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;
        if (n == 1)
            return 1;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int step = 1;
        q.push({0, 0});
        vis[0][0] = true;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty()) {
            int size = q.size();
            while (size) {
                auto [row, col] = q.front();
                q.pop();
                if (row == n - 1 && col == n - 1)
                    return step;

                for (int i = 0; i < 8; i++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < n && !grid[newRow][newCol] &&
                        !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
                size--;
            }
            step++;
        }

        return -1;
    }
};