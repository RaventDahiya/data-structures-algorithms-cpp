
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome.
        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Step 1: Precompute costs for all substrings.
        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {
                int j = i + len - 1;
                int best = INF;

                // Try every proper divisor of len.
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Process each of the d groups.
                    for (int offset = 0; offset < d; offset++) {
                        int l = i + offset;

                        // Last index in this group.
                        int r = i + offset
                              + ((len - 1 - offset) / d) * d;

                        // Count mismatched palindrome pairs.
                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        // Step 2: DP for exactly k substrings.
        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {

                // Last substring is s[j...i-1].
                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    if (dp[p - 1][j] == INF)
                        continue;

                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
