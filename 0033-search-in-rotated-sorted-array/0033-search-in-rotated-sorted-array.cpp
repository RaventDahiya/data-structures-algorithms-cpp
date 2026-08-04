class Solution {
public:
    int search(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size()-1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==t) return mid;
            if(nums[s]<=nums[mid]){
                if(t>=nums[s] && t<=nums[mid]) e = mid - 1;
                else s = mid + 1;
            }else{
                if(t>=nums[mid] && t<=nums[e]) s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};