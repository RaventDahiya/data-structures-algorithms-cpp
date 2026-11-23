
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        // DFS to find new parents
        function<void(int)> dfs = [&](int node) {
            int c = s[node] - 'a';
            int old = last[c];

            if (node != 0 && old != -1) {
                newParent[node] = old;
            }

            last[c] = node;

            for (int child : adj[node]) {
                dfs(child);
            }

            last[c] = old;
        };

        dfs(0);

        // Build modified tree
        adj.assign(n, {});
        for (int i = 1; i < n; i++) {
            adj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        vector<int> ans(n);

        function<int(int)> dfsSize = [&](int node) {
            int size = 1;

            for (int child : adj[node]) {
                size += dfsSize(child);
            }

            return ans[node] = size;
        };

        dfsSize(0);

        return ans;
    }
};
