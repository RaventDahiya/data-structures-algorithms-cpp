class Solution {
public:
    unordered_map<string,bool>dp;

    bool solve(string s,int i,int balance){
        if(i==s.length()){
            return balance==0;
        }
        string str = to_string(i)+to_string(balance);
        if(dp.find(str) != dp.end()) return dp[str];
        bool ans = false;
        if(s[i]=='('){
            ans = ans || solve(s,i+1,balance+1);
        }else if(s[i]=='*'){
            ans = ans || solve(s,i+1,balance);
            ans = ans || solve(s,i+1,balance+1);
            if(balance-1 >= 0) ans = ans || solve(s,i+1,balance-1);
        }else{
            if(balance-1 >= 0) ans = ans || solve(s,i+1,balance-1);
        }
        return dp[str] = ans;
    }
    bool checkValidString(string s) {
        return solve(s,0,0);
    }
};