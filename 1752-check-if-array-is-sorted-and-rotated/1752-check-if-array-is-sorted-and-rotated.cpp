class Solution {
public:
    bool check(vector<int>& nums) {
        int change = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]) change++;
        }
        if(change == 0) return true;
        if(change > 1) return false;
        if(nums[n-1] <= nums[0]) return true;
        return false;
    }
};