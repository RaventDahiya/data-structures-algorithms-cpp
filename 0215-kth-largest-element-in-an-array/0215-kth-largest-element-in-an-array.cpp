class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int idx = nums.size()-k;
        nth_element(nums.begin(),nums.begin()+idx,nums.end());
        return nums[idx];
    }
};