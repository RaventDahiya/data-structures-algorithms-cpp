class Solution {
public:
    set<vector<int>>st;
    void bt(vector<int>&nums,int i,vector<int>&curr){
        st.insert(curr);
        for(int j=i;j<nums.size();j++){
            curr.push_back(nums[j]);
            bt(nums,j+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        sort(nums.begin(),nums.end());
        bt(nums,0,curr);
        vector<vector<int>>res(st.begin(),st.end());
        
        return res;
    }
};