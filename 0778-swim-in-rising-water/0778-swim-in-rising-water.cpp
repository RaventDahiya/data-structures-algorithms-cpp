class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();

            int i = cell.first;
            int j = cell.second;

            if(d > dist[i][j]) continue;

            if(i == n-1 && j == n-1)
                return d;

            for(int dir = 0; dir < 4; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];

                if(x >= 0 && x < n && y >= 0 && y < n) {

                    int newDist = max(d, grid[x][y]);

                    if(newDist < dist[x][y]) {
                        dist[x][y] = newDist;
                        pq.push({newDist, {x, y}});
                    }
                }
            }
        }

        return -1;
    }
};