class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longInc = 1;
        int longDec = 1;
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                longDec++;
            }else{
                longDec = 1;
            }

            if(nums[i] > nums[i-1]){
                longInc++;
            }else{
                longInc = 1;
            }
            ans = max(ans,max(longInc,longDec));
        }
        return ans;
    }
};