class Solution {
public:
    int m, n;

    bool solve(string& s, string& p, int i, int j,
               vector<vector<int>>& dp) {

        if (j == n)
            return i == m;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Does current character match?
        bool match = (i < m &&
                     (s[i] == p[j] || p[j] == '.'));

        bool ans;

        // Next character is '*'
        if (j + 1 < n && p[j + 1] == '*') {

            // 0 occurrences of p[j]
            ans = solve(s, p, i, j + 2, dp);

            // 1 or more occurrences
            if (match)
                ans = ans || solve(s, p, i + 1, j, dp);
        }
        else {
            // Normal character / '.'
            ans = match &&
                  solve(s, p, i + 1, j + 1, dp);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();

        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1, -1)
        );

        return solve(s, p, 0, 0, dp);
    }
};