class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mp;
        stack<int>st; //dec stack

        //R->L store values
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int>ng;
        for(int i=0;i<nums1.size();i++){
            ng.push_back(mp[nums1[i]]); 
        }
        return ng;
        
    }
};