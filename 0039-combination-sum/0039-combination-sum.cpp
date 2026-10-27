class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>& candidates, int target,vector<int>&curr,int i){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(i==candidates.size()) return;

        if(target-candidates[i] >= 0){
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],curr,i);
            curr.pop_back();
        }
        solve(candidates,target,curr,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(candidates,target,curr,0);
        return res;
    }
};