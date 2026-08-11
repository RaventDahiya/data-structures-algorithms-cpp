class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int curr = nums[i];
            mp[curr] = i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int curr = nums[i];
            int find = target - curr;
            if(mp.count(find) && i!=mp[find]){
                return {i,mp[find]};
            }
        }
        return ans;
    }
};