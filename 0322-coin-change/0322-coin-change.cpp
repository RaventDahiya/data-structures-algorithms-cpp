class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        // Base case: only last coin available
        for (int amo = 0; amo <= amount; amo++) {
            if (amo % coins[n - 1] == 0)
                dp[n - 1][amo] = amo / coins[n - 1];
        }

        // Build from second-last coin towards first
        for (int i = n - 2; i >= 0; i--) {

            for (int amo = 0; amo <= amount; amo++) {

                int takeAndStay = INF;

                // Take current coin and STAY at i
                if (amo >= coins[i]) {
                    takeAndStay =
                        1 + dp[i][amo - coins[i]];
                }

                // Skip current coin → move to i+1
                int skip = dp[i + 1][amo];

                dp[i][amo] = min(takeAndStay, skip);
            }
        }

        int ans = dp[0][amount];

        return ans >= INF ? -1 : ans;
    }
};