class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(auto &num : nums){
            ans += abs(num-max_ele);
        }
        return ans;
    }
};