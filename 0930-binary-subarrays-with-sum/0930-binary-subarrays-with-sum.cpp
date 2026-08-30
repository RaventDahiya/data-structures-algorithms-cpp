class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefix;
        prefix[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            if(prefix.count(sum-goal)) count += prefix[sum-goal];

            prefix[sum]++;
        }
        return count;
    }
};