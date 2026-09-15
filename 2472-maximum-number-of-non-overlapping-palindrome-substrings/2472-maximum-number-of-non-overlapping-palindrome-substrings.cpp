class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i,int j, int &k,int &n,vector<vector<int>>&dp){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(s,i,j)){
            int take = 1 + solve(s,j+1,j+k,k,n,dp);
            int grow = solve(s,i,j+1,k,n,dp);
            int slide = solve(s,i+1,j+1,k,n,dp);
            return  dp[i][j] = max(take,max(grow,slide));
        }
        int grow = solve(s,i,j+1,k,n,dp);
        int slide = solve(s,i+1,j+1,k,n,dp);
        return  dp[i][j] = max(grow,slide);
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if(n<k) return 0;
        if(k==1) return n;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,k-1,k,n,dp);
        
    }
};