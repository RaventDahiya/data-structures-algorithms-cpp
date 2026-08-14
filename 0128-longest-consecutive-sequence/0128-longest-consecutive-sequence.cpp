class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int len = 1;
            if(!st.count(num-1)){
                int tofind = num + 1;
                st.erase(num);
                while(st.count(tofind)){
                    len++;
                    st.erase(tofind);
                    tofind++;
                }
            }
            maxi = max(maxi,len);
        }
        return maxi;
    }
};