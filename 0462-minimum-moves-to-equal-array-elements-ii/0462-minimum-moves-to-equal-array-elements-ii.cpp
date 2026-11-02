class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        int mid_ele = nums[n/2];
        int ans = 0;
        for(auto &num : nums){
            ans += abs(num-mid_ele);
        }
        return ans;
    }
};