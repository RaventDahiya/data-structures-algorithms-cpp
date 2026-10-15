class Solution {
public:
    bool isPalindrome(string &str,int i,int j){
        while(i<j){
            if(str[i++]!=str[j--]) return false;
        }
        return true;
    }
    void bt(string &s, vector<string> &curr,vector<vector<string>>&res,int i){
        int n = s.length();
        if(i==n){
            res.push_back(curr);
        }

        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                curr.push_back(s.substr(i, j - i + 1));
                bt(s,curr,res,j+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> curr;
        bt(s,curr,res,0);
        return res;
    }
};