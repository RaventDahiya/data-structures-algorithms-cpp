class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];

        int ans = nums[0];

        for(int i=1;i<nums.size();i++){
            int num = nums[i];

            if(num < 0) swap(maxi,mini);

            maxi = max(num,num*maxi);
            mini = min(num,num*mini);

            ans = max(maxi,ans);
        }

        return ans;
    }
};