class Solution {
public:
    bool solve(string &s1, string &s2, string &s3,
               int i, int j,
               vector<vector<int>> &dp) {

        int x = s1.size();
        int y = s2.size();

        if (i == x && j == y)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        int k = i + j;

        bool ans = false;

        if (i < x && s1[i] == s3[k]) {
            ans = solve(s1, s2, s3, i + 1, j, dp);
        }

        if (!ans && j < y && s2[j] == s3[k]) {
            ans = solve(s1, s2, s3, i, j + 1, dp);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();

        if (x + y != s3.size())
            return false;

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

        return solve(s1, s2, s3, 0, 0, dp);
    }
};