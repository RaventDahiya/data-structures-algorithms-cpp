class Solution {
public:
    int solve(vector<int>& nums,int i,int prevIndex,vector<vector<int>>&dp){
        if(i == nums.size()) return 0;
        if(dp[i][prevIndex+1] !=-1) return dp[i][prevIndex+1];
        int take = 0;
        if(prevIndex==-1 || nums[i] > nums[prevIndex]){
            take = 1 + solve(nums,i+1,i,dp);
        }
        int skip = solve(nums,i+1,prevIndex,dp);

        return dp[i][prevIndex+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return solve(nums,0,-1,dp);
    }
};