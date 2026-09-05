class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    int nodeColor = color[node];

                    for (int nbr : graph[node]) {
                        if (color[nbr] == -1) {
                            if (nodeColor == 0)
                                color[nbr] = 1;
                            else
                                color[nbr] = 0;
                            q.push(nbr);
                        } else if (color[nbr] == nodeColor)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};