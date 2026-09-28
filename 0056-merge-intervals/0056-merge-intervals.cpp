class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin(),inter.end());
        vector<vector<int>>ans;
        ans.push_back(inter[0]);
        int i = 0;
        for(int j=1;j<n;j++){
            if(ans[i][1] >= inter[j][0]){
                if(ans[i][1]>=inter[j][1]){
                    continue;
                }
                ans[i] = {ans[i][0],inter[j][1]};
            }else{
                ans.push_back(inter[j]);
                i++;
            }
        }
        return ans;
    }
};