class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1;
        for(auto& num : nums1){
            st1.insert(num);
        }
        unordered_set<int>st2;
        for(auto& num : nums2){
            if(st1.count(num)) st2.insert(num);
        }
        vector<int>ans(st2.begin(),st2.end());
        return ans;
    }
};