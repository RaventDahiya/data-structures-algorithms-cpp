class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m]==target) return m;
            if (nums[m] >= nums[l]) { // left is sorted
                if(target >= nums[l] && target<=nums[m]){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }else{ //right is sorted
                if(target>=nums[m] && target<=nums[r]){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};