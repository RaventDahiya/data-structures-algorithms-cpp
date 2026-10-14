class Solution {
public:
    void bt(int n,int k,int str,vector<int>&curr,vector<vector<int>>&res){

        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        if (str>n) return;
        //pick
        curr.push_back(str);
        bt(n,k,str+1,curr,res);
        curr.pop_back();
        //skip
        bt(n,k,str+1,curr,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        vector<vector<int>>res;
        bt(n,k,1,curr,res);
        return res;
    }
};