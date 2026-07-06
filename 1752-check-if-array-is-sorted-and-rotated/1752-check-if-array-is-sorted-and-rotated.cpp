class Solution {
public:
    bool check(vector<int>& nums) {
        int change = 0;
        int n = nums.size();
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                change++;
            }
        }
        if(change==0) return true;
        if(change == 1 && nums[n-1]<=nums[0]) return true;
        return false;
    }
};