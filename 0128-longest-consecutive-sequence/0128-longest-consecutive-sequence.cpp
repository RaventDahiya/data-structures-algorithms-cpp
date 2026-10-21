class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &num : nums){
            st.insert(num);
        }
        int longest = 0;
        for(auto &num : nums){
            if(st.count(num-1)) continue;
            int currLen = 0;
            int toFind = num;
            while(st.count(toFind)){
                currLen++; 
                st.erase(toFind);
                toFind++;
            }
            longest = max(longest,currLen);
        }

        return longest;
    }
};