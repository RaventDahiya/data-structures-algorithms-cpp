class Solution {
public:
    vector<vector<int>>res;
    int N;
    void solve(vector<int>&curr,int k,int n,int i){
        if(n==0 && curr.size()==k){
            res.push_back(curr);
            return;
        }
        if(i>9 || curr.size()==k) return;
        if(curr.size() < k && n-i>=0){
            curr.push_back(i);
            solve(curr,k,n-i,i+1);
            curr.pop_back();
        }
        if(curr.size() < k){
            solve(curr,k,n,i+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        N = n;
        vector<int>curr;
        solve(curr,k,n,1);
        return res;
    }
};