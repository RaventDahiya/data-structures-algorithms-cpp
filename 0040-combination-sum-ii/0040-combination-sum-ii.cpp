
class Solution {
public:
    vector<vector<int>> res;

    void bt(vector<int>& can, int tar,
            vector<int>& curr, int str) {

        if (tar == 0) {
            res.push_back(curr);
            return;
        }

        if (str == can.size()) return;

        // Include current element
        if (tar - can[str] >= 0) {
            curr.push_back(can[str]);

            bt(can, tar - can[str], curr, str + 1);

            curr.pop_back();
        }

        // Exclude current element and all its duplicates
        int next = str + 1;

        while (next < can.size() && can[next] == can[str]) {
            next++;
        }

        bt(can, tar, curr, next);
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        res.clear();
        sort(can.begin(), can.end());

        vector<int> curr;
        bt(can, tar, curr, 0);

        return res;
    }
};
