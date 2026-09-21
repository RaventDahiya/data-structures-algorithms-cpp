class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &num : nums){
            st.insert(num);
        }
        int maxi = INT_MIN;
        for(auto &num : st){
            if(st.count(num-1)) continue;
            int count = 1;
            int toFind = num + 1;
            while(st.count(toFind)){
                count++;
                toFind++;
            }
            maxi = max(maxi,count);
        }
        return maxi==INT_MIN ? 0 : maxi;
    }
};