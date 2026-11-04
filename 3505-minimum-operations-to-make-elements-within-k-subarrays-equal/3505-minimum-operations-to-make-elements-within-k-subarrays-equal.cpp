class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        vector<long long> cost(n - x + 1);

        int target = (x + 1) / 2;

        // Balance both multisets
        auto rebalance = [&]() {
            while (left.size() > target) {
                int val = *left.rbegin();

                left.erase(left.find(val));
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < target && !right.empty()) {
                int val = *right.begin();

                right.erase(right.find(val));
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        };

        // Insert element
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } 
            else {
                right.insert(val);
                sumRight += val;
            }

            rebalance();
        };

        // Remove element
        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } 
            else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }

            rebalance();
        };

        // Build first window
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        // Calculate cost for every window
        for (int i = 0; i <= n - x; i++) {

            long long median = *left.rbegin();

            cost[i] =
                median * (long long)left.size() - sumLeft +
                sumRight - median * (long long)right.size();

            if (i + x < n) {
                remove(nums[i]);
                add(nums[i + x]);
            }
        }

        // DP
        const long long INF = 1e18;

        // Ring buffer of x + 1 rows
        int sz = x + 1;

        vector<vector<long long>> dp(
            sz, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            int curr = i % sz;
            int prev = (i - 1) % sz;
            int source = (i - x + sz) % sz;

            // Reset current row
            fill(dp[curr].begin(), dp[curr].end(), INF);

            dp[curr][0] = 0;

            for (int j = 1; j <= k; j++) {

                // Option 1: Skip current element
                dp[curr][j] = dp[prev][j];

                // Option 2: Select window of size x
                if (i >= x && dp[source][j - 1] != INF) {

                    dp[curr][j] = min(
                        dp[curr][j],
                        dp[source][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n % sz][k];
    }
};