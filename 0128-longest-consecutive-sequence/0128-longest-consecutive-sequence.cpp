class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto& num : nums){
            st.insert(num);
        }
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            int curr = nums[i];
            int find = nums[i];
            while(st.count(find)){
                st.erase(find);
                count++;
                find++;
            }
            find = curr-1;
            while(st.count(find)){
                st.erase(find);
                count++;
                find--;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};