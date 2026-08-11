class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>st;
        for(auto& num : nums){
            st.insert(num);
        }
        for(int i=0;i<=nums.size();i++){
            if(!st.count(i)) return i;
        }
        return -1;
    }
};