class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> col(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                q.push(i);
                col[i] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    int parentColor = col[node];
                    for (auto nbr : adj[node]) {
                        if (col[nbr] == -1) {
                            if (parentColor == 0) {
                                col[nbr] = 1;
                            } else {
                                col[nbr] = 0;
                            }
                            q.push(nbr);
                        } else if (col[nbr] == parentColor)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};