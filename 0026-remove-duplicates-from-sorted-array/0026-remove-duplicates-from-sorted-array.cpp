class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int s = 0;
        for(int f=1;f<n;f++){
            if(nums[s] != nums[f]){
                s++;
                swap(nums[s],nums[f]);
            }
        }
        return s + 1;
    }
};