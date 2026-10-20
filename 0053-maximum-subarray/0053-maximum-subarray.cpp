class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(maxSum,currSum);
        }

        return maxSum;
    }
};