class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mini = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= nums[l]) { // left is sorted
                mini = min(nums[l],mini);
                l = m + 1;
            } else { // right is sorted
                mini = min(mini,nums[m]);
                r = m - 1;
            }
        }
        return mini;
    }
};