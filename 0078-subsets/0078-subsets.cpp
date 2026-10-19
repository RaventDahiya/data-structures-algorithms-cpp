class Solution {
public:
    vector<vector<int>>res;
    void bt(vector<int>&nums,vector<int>&curr,int str){
        res.push_back(curr);

        for(int i=str;i<nums.size();i++){
            curr.push_back(nums[i]);
            bt(nums,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        bt(nums,curr,0);
        return res;
    }
};