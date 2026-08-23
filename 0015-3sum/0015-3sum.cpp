class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<=n-3;i++){
            int num = nums[i];
            if(i>0 && num==nums[i-1]) continue;
            int l = i + 1;
            int e = n - 1;
            while(l<e){
                int sum = num + nums[l] + nums[e];
                if(sum == 0){
                    ans.push_back({num,nums[l],nums[e]});
                    while(l<e && nums[l]==nums[l+1]) l++;
                    while(l<e && nums[e]==nums[e-1]) e--;
                    l++; e--;
                }else if(sum > 0){
                    e--;
                }else{
                    l++;
                }
                
            }
        }
        return ans;
    }
};