
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);

        long long k = (long long)k1 + k2;
        long long total = 0;
        long long maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs((long long)nums1[i] - nums2[i]);
            total += diff[i];
            maxi = max(maxi, diff[i]);
        }

        if (total <= k) return 0;

        long long low = 0, high = maxi;

        // Find the minimum feasible maximum difference
        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long operations = 0;

            for (long long d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long level = low;

        // Reduce every difference to at most 'level'
        for (long long &d : diff) {
            if (d > level) {
                k -= d - level;
                d = level;
            }
        }

        // Calculate squared sum
        long long ans = 0;
        for (long long d : diff) {
            ans += d * d;
        }

        // Use remaining operations on values == level
        ans -= k * (2 * level - 1);

        return ans;
    }
};
