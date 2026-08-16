class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int maxi = 0;

        for(auto num : nums){
            if(num == 1) len++;
            else{
                maxi = max(maxi,len);
                len = 0;
            }
        }
        maxi = max(maxi,len);
        return maxi;
    }
};