class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> absDiff(n, vector<int>(m, INT_MAX));
        absDiff[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        int x[] = {0, -1, 0, 1};
        int y[] = {-1, 0, 1, 0};
        while (!pq.empty()) {
            auto [diff, v] = pq.top(); pq.pop();
            auto [row, col] = v;
            if (diff > absDiff[row][col]) continue;
            for (int i = 0; i < 4; i++) {
                int newX = row + x[i];
                int newY = col + y[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) { // valid index
                    int currDiff = abs(h[row][col] - h[newX][newY]);
                    int maxDiff = max(diff, currDiff);
                    if (maxDiff < absDiff[newX][newY]) {
                        absDiff[newX][newY] = maxDiff;
                        pq.push({maxDiff, {newX, newY}});
                    }
                }
            }
        }
        return absDiff[n - 1][m - 1];
    }
};