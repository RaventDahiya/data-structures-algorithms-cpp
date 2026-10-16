class Solution {
public:
    bool backtrackKSubsets(vector<int>& nums, vector<int>& buckets, int idx,
                           int target) {
        if (idx == (int)nums.size()) {
            // Check all buckets equal target (should be, if sum matches)
            return true;
        }

        for (int i = 0; i < (int)buckets.size(); i++) {
            // PRUNE 1: bucket would overflow
            if (buckets[i] + nums[idx] > target)
                continue;

            // PRUNE 2: skip duplicate bucket states (same value = same outcome)
            if (i > 0 && buckets[i] == buckets[i - 1])
                continue;

            // CHOOSE
            buckets[i] += nums[idx];

            // EXPLORE
            if (backtrackKSubsets(nums, buckets, idx + 1, target))
                return true;

            // UNCHOOSE
            buckets[i] -= nums[idx];

            // PRUNE 3: if bucket is empty after removing, no point trying other
            // empty buckets
            if (buckets[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % k != 0)
            return false;

        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // PRUNE: try largest first

        if (nums[0] > target)
            return false;

        vector<int> buckets(k, 0);
        return backtrackKSubsets(nums, buckets, 0, target);
    }
};