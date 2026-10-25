class Solution {
public:
    vector<vector<string>> res;

    void solve(int n, vector<string>& grid, int i,
               vector<bool>& col,
               vector<bool>& diagonal1,
               vector<bool>& diagonal2) {

        if (i == n) {
            res.push_back(grid);
            return;
        }

        for (int j = 0; j < n; j++) {
            int d1 = i + j;
            int d2 = i - j + n - 1;

            if (col[j] || diagonal1[d1] || diagonal2[d2])
                continue;

            grid[i][j] = 'Q';
            col[j] = diagonal1[d1] = diagonal2[d2] = true;

            solve(n, grid, i + 1, col, diagonal1, diagonal2);

            grid[i][j] = '.';
            col[j] = diagonal1[d1] = diagonal2[d2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        res.clear();

        vector<string> grid(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diagonal1(2*n, false);
        vector<bool> diagonal2(2*n, false);

        solve(n, grid, 0, col, diagonal1, diagonal2);

        return res;
    }
};