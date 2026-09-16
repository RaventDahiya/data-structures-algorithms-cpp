class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int n, int i, int k, int open) {
        if (k == 0)
            return open ? 0 : 1;

        if (i >= n)
            return 0;

        if (dp[i][k][open] != -1)
            return dp[i][k][open];

        long long ans = 0;

        if (!open) {
            // Don't start a segment at i
            ans += solve(n, i + 1, k, 0);

            // Start a segment at i
            ans += solve(n, i + 1, k, 1);
        }
        else {
            // Continue current segment
            ans += solve(n, i + 1, k, 1);

            // End current segment at i
            // i can also be reused as start of next segment
            ans += solve(n, i, k - 1, 0);
        }

        return dp[i][k][open] = ans % mod;
    }

public:
    int numberOfSets(int n, int k) {
        dp.assign(n + 1,
                  vector<vector<int>>(k + 1,
                  vector<int>(2, -1)));

        return solve(n, 0, k, 0);
    }
};