class Solution {
public:
    
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans = {-1,-1};
        for(int i=0;i<mat.size();i++){
            vector<int>temp = mat[i];
            sort(temp.begin(),temp.end());
            auto it = upper_bound(temp.begin(),temp.end(),0);
            int idx = it - temp.begin();
            int totalOne = temp.size() - idx;
            if(totalOne > ans[1]){
                ans[0] = i;
                ans[1] = totalOne;
            }
        }
        return ans;
    }
};