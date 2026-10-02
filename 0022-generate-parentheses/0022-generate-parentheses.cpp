class Solution {
public:
    int N;
    vector<string>ans;
    void solve(int open,int close,string str){
        if(open==N && close==N){
            ans.push_back(str);
            return;
        }
        

        //add (
        if(open < N){
            solve(open+1,close,str+'(');
        }
        

        //add )
        if(close+1 <= open){
            solve(open,close+1,str+')');
        }

    }
    vector<string> generateParenthesis(int n) {
        N = n;
        string temp = "";
        solve(0,0,temp);
        return ans;
    }
};