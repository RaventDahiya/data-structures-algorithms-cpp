class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid_ele = nums[n/2];
        int ans = 0;
        for(auto &num : nums){
            ans += abs(num-mid_ele);
        }
        return ans;
    }
};