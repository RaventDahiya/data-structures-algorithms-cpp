class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n>1 && nums[0] > nums[1]) return 0;
        if(n>1 && nums[n-1] > nums[n-2]) return n-1;

        int i = 1;
        int j = n-2;

        while(i<j){
            int mid = i + (j-i)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if(nums[mid+1] > nums[mid]){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }

        return j;
    }
};