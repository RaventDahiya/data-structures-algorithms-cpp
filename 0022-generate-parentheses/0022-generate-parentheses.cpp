class Solution {
public:
    vector<string>res;

    void bt(int &n,int o,int c,string &str){
        if(o==n && c==n){
            res.push_back(str);
            return;
        }
        if(o>n) return;

        str.push_back('(');
        bt(n,o+1,c,str);
        str.pop_back();

        if(o>=c+1){
            str.push_back(')');
            bt(n,o,c+1,str);
            str.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        bt(n,0,0,str);
        return res;
    }
};