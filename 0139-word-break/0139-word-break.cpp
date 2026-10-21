class Solution {
public:
    bool solve(string& s, int startIndex, unordered_set<string>& st,vector<int>&dp) {
        int n = s.length();

        if (startIndex == n) return true;
        if(dp[startIndex]!=-1) return dp[startIndex];

        string str = "";
        for (int j = startIndex; j < n; j++) {
            str += s[j];
            if (st.count(str)) {
                if (solve(s, j + 1, st,dp)) return dp[startIndex]=1;
            }
        }

        return dp[startIndex]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto& str : wordDict) {
            st.insert(str);
        }
        vector<int>dp(s.length(),-1);
        return solve(s, 0, st,dp);
    }
};