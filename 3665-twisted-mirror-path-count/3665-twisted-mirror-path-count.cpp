class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;

    int dp[505][505][2][2];

    int solve(vector<vector<int>>& grid, int i, int j, int left, int right) {
        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        int &ans = dp[i][j][left][right];

        if (ans != -1)
            return ans;

        int total = 0;

        if (grid[i][j] == 0) {
            total = (solve(grid, i, j + 1, 1, 0) +
                     solve(grid, i + 1, j, 0, 1)) % mod;
        } else {
            if (left == 1) {
                total = solve(grid, i + 1, j, 0, 1);
            } else {
                total = solve(grid, i, j + 1, 1, 0);
            }
        }

        return ans = total;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, 0, 0);
    }
};