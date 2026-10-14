class Solution {
public:
    void bt(int n,int k,int str,vector<int>&curr,vector<vector<int>>&res){

        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        if (str>n) return;

        for(int i=str;i<=n;i++){
            curr.push_back(i);
            bt(n, k, i + 1, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        vector<vector<int>>res;
        bt(n,k,1,curr,res);
        return res;
    }
};