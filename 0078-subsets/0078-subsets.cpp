class Solution {
public:
    void bt(vector<int>& nums, int i, vector<int>& curr,vector<vector<int>>& res) {
        res.push_back(curr);

        for (int j = i; j < nums.size(); j++) {
            curr.push_back(nums[j]);
            bt(nums, j + 1, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        bt(nums, 0, curr, res);
        return res;
    }
};