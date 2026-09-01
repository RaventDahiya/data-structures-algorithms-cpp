class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Put all 0s into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Multi-source BFS
        while(!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();

            ans[row][col] = dist;

            for(int dir = 0; dir < 4; dir++) {
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];

                if(newRow >= 0 && newRow < m &&
                   newCol >= 0 && newCol < n &&
                   !vis[newRow][newCol]) {

                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol, dist + 1});
                }
            }
        }

        return ans;
    }
};