class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return 0.0;
        double ans =    INT_MIN;
        double temp = 0;
        for(int i=0;i<k;i++){
            temp += nums[i];
        }
        ans = max(ans,temp/k);

        for(int i=k;i<n;i++){
            temp -= nums[i-k];
            temp += nums[i];
            ans = max(ans,temp/k);
        }

        return ans;
    }
};