class Solution {
public:
    vector<vector<string>>res;
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(string &s,vector<string>&curr,int i){
        int n = s.length();
        if(i==n){
            res.push_back(curr);
            return;
        }

        
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                solve(s,curr,j+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string>curr;
        solve(s,curr,0);
        return res;
    }
};