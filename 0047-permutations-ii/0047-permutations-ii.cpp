class Solution {
public:
    void bt(vector<int>& nums,vector<bool>& used,vector<int>& curr,vector<vector<int>>&res){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            bt(nums,used,curr,res);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<bool>used(n,false);
        vector<int>curr;
        vector<vector<int>>res;
        bt(nums,used,curr,res);
        return res;
    }
};