class Solution {
public:
    bool isValid(vector<int>& nums, int k,int maxSum){
        int sum = 0;
        int partion = 1;
        for(auto it : nums){
            if(sum + it <= maxSum){
                sum += it;
            }else{
                partion++;
                sum = it;
            }
        }
        return partion<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k ) return -1;

        long long left = 0;
        long long right = 0;

        for(auto it : nums){
            left = max(left,(long long)it);
            right += it;
        }

        int result = right;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(isValid(nums,k,mid)){
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return result;
    }
};