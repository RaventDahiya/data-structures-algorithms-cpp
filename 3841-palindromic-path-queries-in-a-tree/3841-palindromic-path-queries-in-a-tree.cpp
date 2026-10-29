class Solution {
    int LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, prefix;

    class Fenwick {
        int n;
        vector<int> bit;

    public:
        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            for (; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        }

        int query(int idx) {
            int result = 0;

            for (; idx > 0; idx -= idx & -idx) {
                result ^= bit[idx];
            }

            return result;
        }
    };

    int getBit(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int root, const string& s) {
        // Iterative DFS avoids stack overflow on a long tree.
        stack<tuple<int, int, bool>> st;
        st.push({root, root, false});

        while (!st.empty()) {
            auto [u, p, exiting] = st.top();
            st.pop();

            if (!exiting) {
                tin[u] = timer++;

                up[u][0] = p;

                for (int j = 1; j < LOG; j++) {
                    up[u][j] = up[up[u][j - 1]][j - 1];
                }

                prefix[u] = (u == root)
                    ? getBit(s[u])
                    : prefix[p] ^ getBit(s[u]);

                st.push({u, p, true});

                for (int v : adj[u]) {
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push({v, u, false});
                }
            } else {
                tout[u] = timer;
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    int getPrefix(int u, Fenwick& fw) {
        return prefix[u] ^ fw.query(tin[u] + 1);
    }

    bool canFormPalindrome(int mask) {
        return (mask & (mask - 1)) == 0;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        timer = 0;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        prefix.assign(n, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, s);

        Fenwick fw(n);
        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);

            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = getBit(s[u]) ^ getBit(c);

                if (delta != 0) {
                    // Apply XOR to the entire subtree of u.
                    fw.update(tin[u] + 1, delta);
                    fw.update(tout[u] + 1, delta);

                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = getPrefix(u, fw)
                         ^ getPrefix(v, fw)
                         ^ getBit(s[w]);

                ans.push_back(canFormPalindrome(mask));
            }
        }

        return ans;
    }
};