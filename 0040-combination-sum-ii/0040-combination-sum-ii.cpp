class Solution {
public:
    void solve(vector<int>& candidates, int target, int src, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(temp);
            return;
        }


        for (int i = src; i < candidates.size(); i++) {

            // Skip duplicate at SAME recursion level
            if (i > src && candidates[i] == candidates[i - 1]) continue;

            // Sorted array, so everything after this is also too large
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};