class Solution {
public:

    struct Node {
        int prod;
        long long cnt[5];
        bool valid;

        Node() {
            prod = 1;
            valid = false;

            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int K;
    int n;
    vector<Node> tree;


    Node mergeNode(const Node& left, const Node& right) {

        if (!left.valid)
            return right;

        if (!right.valid)
            return left;

        Node ans;
        ans.valid = true;

        // Product of complete segment
        ans.prod = (left.prod * right.prod) % K;

        // Prefix completely inside left
        for (int r = 0; r < K; r++) {
            ans.cnt[r] = left.cnt[r];
        }

        // Complete left + prefix of right
        for (int r = 0; r < K; r++) {

            int newRem =
                (left.prod * r) % K;

            ans.cnt[newRem] += right.cnt[r];
        }

        return ans;
    }


    void build(int node, int l, int r,
               vector<int>& nums) {

        if (l == r) {

            tree[node].valid = true;

            int rem = nums[l] % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] =
            mergeNode(
                tree[node * 2],
                tree[node * 2 + 1]
            );
    }


    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {

            // reset
            for (int i = 0; i < 5; i++)
                tree[node].cnt[i] = 0;

            int rem = value % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            tree[node].valid = true;

            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {

            update(
                node * 2,
                l,
                mid,
                index,
                value
            );

        } else {

            update(
                node * 2 + 1,
                mid + 1,
                r,
                index,
                value
            );
        }

        tree[node] =
            mergeNode(
                tree[node * 2],
                tree[node * 2 + 1]
            );
    }


    Node query(int node, int l, int r,
               int ql) {

        // Completely before start
        if (r < ql)
            return Node();

        // Completely inside [ql, n-1]
        if (l >= ql)
            return tree[node];

        int mid = l + (r - l) / 2;

        Node left =
            query(node * 2, l, mid, ql);

        Node right =
            query(node * 2 + 1, mid + 1, r, ql);

        return mergeNode(left, right);
    }


    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        K = k;
        n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // We only ever query [start, n-1]
            Node range =
                query(
                    1,
                    0,
                    n - 1,
                    start
                );

            result.push_back(
                (int)range.cnt[x]
            );
        }

        return result;
    }
};