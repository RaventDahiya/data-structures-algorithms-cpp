
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;

    void apply(int idx, int l, int r, long long val) {
        long long len = r - l + 1;
        val %= MOD;

        seg[idx].sq = (
            seg[idx].sq +
            2LL * val % MOD * seg[idx].sum % MOD +
            val * val % MOD * len % MOD
        ) % MOD;

        seg[idx].sum = (
            seg[idx].sum + val * len
        ) % MOD;

        seg[idx].lazy = (
            seg[idx].lazy + val
        ) % MOD;
    }

    void push(int idx, int l, int r) {
        if (seg[idx].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(idx * 2, l, mid, seg[idx].lazy);
        apply(idx * 2 + 1, mid + 1, r, seg[idx].lazy);

        seg[idx].lazy = 0;
    }

    void update(int idx, int l, int r,
                int ql, int qr) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(idx, l, r, 1);
            return;
        }

        push(idx, l, r);

        int mid = l + (r - l) / 2;

        update(idx * 2, l, mid, ql, qr);
        update(idx * 2 + 1, mid + 1, r, ql, qr);

        seg[idx].sum = (
            seg[idx * 2].sum + seg[idx * 2 + 1].sum
        ) % MOD;

        seg[idx].sq = (
            seg[idx * 2].sq + seg[idx * 2 + 1].sq
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        seg.assign(4 * n + 4, Node());

        unordered_map<int, int> last;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + seg[1].sq) % MOD;

            last[nums[i]] = i;
        }

        return (int)ans;
    }
};
