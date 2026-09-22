class Solution {
public:
    bool isValid(vector<int>& nums,int threshold,int d){
        int total = 0;
        for(auto num : nums){
            total += (num/d);
            if(num%d) total++;
        }
        return total<=threshold;
    }
    int smallestDivisor(vector<int>& nums,int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;
        while(l<=r){
            int m = l + (r-l)/2;
            if(isValid(nums,threshold,m)){
                ans = min(ans,m);
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};