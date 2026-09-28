class Solution {
public:
    int solve(vector<int>& nums, int i, int prevIndex,
              vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;
        if (dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];
        int take = 0;
        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }
        int skip = solve(nums, i + 1, prevIndex, dp);

        return dp[i][prevIndex + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int prevIndex = n-1; prevIndex >= -1; prevIndex--) {
                int take = 0;
                if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
                    take = 1 + dp[i+1][i+1];
                }
                int skip = dp[i+1][prevIndex+1];

                dp[i][prevIndex + 1] = max(take, skip);
            }
        }
        return dp[0][0];
    }
};