
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // 1. Build Suffix Array using doubling
        vector<int> sa(n), rank = nums, newRank(n);

        iota(sa.begin(), sa.end(), 0);

        for (int k = 1; k < n; k *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> prev = {
                    rank[a],
                    (a + k < n) ? rank[a + k] : -1
                };

                pair<int, int> curr = {
                    rank[b],
                    (b + k < n) ? rank[b + k] : -1
                };

                newRank[b] = newRank[a] + (prev != curr);
            }

            rank.swap(newRank);

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // 2. Build inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // 3. Build LCP array using Kasai's algorithm
        // lcp[i] = LCP(sa[i], sa[i + 1])
        vector<int> lcp(n - 1, 0);

        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == n - 1) {
                h = 0;
                continue;
            }

            int j = sa[p + 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0)
                h--;
        }

        // 4. Find the minimum unique subarray length
        int ans = n;

        for (int p = 0; p < n; p++) {

            int mx = 0;

            // LCP with previous suffix
            if (p > 0)
                mx = max(mx, lcp[p - 1]);

            // LCP with next suffix
            if (p < n - 1)
                mx = max(mx, lcp[p]);

            // Shortest unique prefix
            int len = mx + 1;

            // Check whether this subarray fits
            if (len <= n - sa[p]) {
                ans = min(ans, len);
            }
        }

        return ans;
    }
};
