class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for(int n : nums){
            xorAll ^= n;
        }
        long long firstBitDiff = (xorAll&(xorAll-1)) ^ xorAll;
        vector<int>ans = {0,0};
        for(int n : nums){
            if(n & firstBitDiff){
                ans[0] ^= n;
            }else{
                ans[1] ^= n;
            }
        }
        return ans;
    }
};