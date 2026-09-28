class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + solve(nums, i + 2, dp);
        int skip = solve(nums, i + 1, dp);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        int curr = 0;
        int next = 0;
        int nextNext = 0;
        for (int i = n-1; i >= 0; i--) {
            int take = nums[i] + nextNext;
            int skip = next;
            curr = max(take, skip);
            nextNext = next;
            next = curr;
            
        }
        return curr;
    }
};