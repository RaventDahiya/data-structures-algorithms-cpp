class Solution {
public:
    int solve(vector<int>& coins, int amount,int i,int n,vector<vector<int>>&dp){
        if(i==n-1){
            if(amount % coins[n-1] == 0) return amount/coins[n-1];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int takeAndStay = INT_MAX;
        if(amount - coins[i] >=0 ){
            takeAndStay = 1 + solve(coins,amount-coins[i],i,n,dp);
        }   
        int skip = solve(coins,amount,i+1,n,dp);

        return dp[i][amount] = min(skip,takeAndStay);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,0,n,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};