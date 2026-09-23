class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOne = 0;
        vector<int>ans = {0,0};
        for(int i=0;i<mat.size();i++){
            auto &arr = mat[i];
            sort(arr.begin(),arr.end());
            auto it = lower_bound(arr.begin(),arr.end(),1);
            int idx = it-arr.begin();
            int n = arr.size();
            if(n-idx > maxOne){
                maxOne = n - idx;
                ans = {i,n-idx};
            }
        }
        return ans;
    }
};