class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        set<pair<int, pair<int, int>>> st;
        st.insert({1, {0, 0}}); // { wt , {row,col }}
        int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!st.empty()) {
            auto [dis, v] = *(st.begin());
            auto [row, col] = v;
            st.erase(st.begin());
            if (dis > dist[row][col]) continue;
            for (int dir = 0; dir < 8; dir++) {
                int newX = row + x[dir];
                int newY = col + y[dir];
                if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                    grid[newX][newY] == 0) {
                    if (dis + 1 < dist[newX][newY]) {
                        if (dist[newX][newY] != INT_MAX) {
                            st.erase({dist[newX][newY],{newX,newY}});
                        }
                        dist[newX][newY] = dis + 1;
                        st.insert({dist[newX][newY], {newX,newY}});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};