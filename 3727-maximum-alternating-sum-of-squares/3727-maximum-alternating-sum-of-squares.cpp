class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i] = -nums[i];
            }
        }
        sort(nums.begin(),nums.end());

        int i=0;
        int j=n-1;

        while(i<j){
            ans += (long long) nums[j] * nums[j];
            ans -= (long long) nums[i] * nums[i];
            j--; i++;
        }
        if(n%2==1) ans += (long long) nums[j] * nums[j];
        return ans;
    }
};