class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //find breaking poit
        int breakingIndex = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakingIndex = i;
                cout<<breakingIndex;
                break;
            }
        }
        if(breakingIndex==-1){
            reverse(nums.begin(),nums.end());
        }else{
            //find min from end 
           for(int i=n-1;i>breakingIndex;i--){
                if(nums[i]>nums[breakingIndex]){
                    swap(nums[i],nums[breakingIndex]);
                    break;
                }
            }
            //reverse the rest array
            reverse(nums.begin()+breakingIndex+1,nums.end());
        }
    }
};