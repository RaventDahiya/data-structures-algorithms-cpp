class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] == 1)
            return false; // Cycle found

        if (color[node] == 2)
            return true; // Already known to be safe

        color[node] = 1; // Mark as visiting

        for (int nbr : graph[node]) {
            if (!dfs(nbr, graph, color))
                return false;
        }

        color[node] = 2; // Mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, color))
                ans.push_back(i);
        }

        return ans;
    }
};