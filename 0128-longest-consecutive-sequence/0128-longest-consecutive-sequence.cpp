class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &num : nums){
            st.insert(num);
        }
        int longest = 0;
        for(auto &num : st){
            if(st.count(num-1)) continue;
            int currLen = 1;
            int toFind = num+1;
            while(st.count(toFind)){
                currLen++; 
                toFind++;
            }
            longest = max(longest,currLen);
        }

        return longest;
    }
};