class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        int maxSumHelper = nums[0];
        int minSumHelper = nums[0];
        int totalSum = nums[0];

        for(int i=1;i<nums.size();i++){
            maxSumHelper = max(nums[i],maxSumHelper+nums[i]);
            minSumHelper = min(nums[i],minSumHelper+nums[i]);

            totalSum += nums[i];

            maxSum = max(maxSum,maxSumHelper);
            minSum = min(minSum,minSumHelper);

        }

        int maxSumCircular = totalSum - minSum;
        if(maxSum > 0) return max(maxSum,maxSumCircular);
        return maxSum;
    }
};