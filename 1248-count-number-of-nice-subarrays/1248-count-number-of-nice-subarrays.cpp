class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
                nums[i] = 0;
            else
                nums[i] = 1;
        }
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (prefix.count(sum - goal))
                count += prefix[sum - goal];

            prefix[sum]++;
        }
        return count;
    }
};