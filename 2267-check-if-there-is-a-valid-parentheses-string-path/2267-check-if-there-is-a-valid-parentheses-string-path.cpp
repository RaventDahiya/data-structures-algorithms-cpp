class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        // Add current character
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid parentheses prefix
        if (balance < 0)
            return false;

        // No need for balance greater than total path length
        if (balance > m + n)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Memoization
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Right
        if (j + 1 < n)
            ans = ans || solve(grid, i, j + 1, balance);

        // Down
        if (i + 1 < m)
            ans = ans || solve(grid, i + 1, j, balance);

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        // Last character must be ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        dp.resize(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

        return solve(grid, 0, 0, 0);
    }
};