class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];

        // If the starting pixel already has the target color
        if (original == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if (ni >= 0 && ni < n &&
                    nj >= 0 && nj < m &&
                    image[ni][nj] == original) {

                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }

        return image;
    }
};