class Solution {
public:
    vector<vector<int>>res;
    void bt(vector<int>& can, int tar,vector<int>&curr,int str){
        if(tar==0){
            res.push_back(curr);
            return;
        }
        if(tar<0) return;

        for(int i=str;i<can.size();i++){
            if(i>str && can[i]==can[i-1]) continue;
            if(tar-can[i]<0) continue;

            curr.push_back(can[i]);
            bt(can,tar-can[i],curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(),can.end());
        vector<int>curr;
        bt(can,tar,curr,0);
        return res;
    }
};