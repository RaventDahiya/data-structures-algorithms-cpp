class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<=n-3;i++){
            if( i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = n-1;

            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && l<n-1 && nums[l]==nums[l+1]) l++;
                    while(l<r && r>1 && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};