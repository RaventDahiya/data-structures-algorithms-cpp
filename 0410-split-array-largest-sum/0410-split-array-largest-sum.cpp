class Solution {
public:
    bool isValid(vector<int>& nums, int k,int maxSum){
        int splits = 1;
        int sum = 0;
        for(auto &num : nums){
            if(sum + num > maxSum){
                splits++;
                sum = num;
                if(splits > k) return false;
            }else{
                sum += num;
            }
        }
        return true;

    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);

        while(l<=r){
            int m = l + (r-l)/2;
            if(isValid(nums,k,m)){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        return l;
    }
};