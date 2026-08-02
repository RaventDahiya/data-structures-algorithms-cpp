class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;

        dist[0][0] = 1;
        q.push({0, 0});

        int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (int dir = 0; dir < 8; dir++) {

                int newX = row + x[dir];
                int newY = col + y[dir];

                if (newX >= 0 && newY >= 0 &&
                    newX < n && newY < n &&
                    grid[newX][newY] == 0) {

                    if (dist[row][col] + 1 < dist[newX][newY]) {

                        dist[newX][newY] = dist[row][col] + 1;

                        q.push({newX, newY});
                    }
                }
            }
        }

        if (dist[n - 1][n - 1] == INT_MAX)
            return -1;

        return dist[n - 1][n - 1];
    }
};