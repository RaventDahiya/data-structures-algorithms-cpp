class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(auto& num : nums){
            mp[num]++;
        }
        vector<vector<int>>bucket(n+1);
        vector<int>ans;
        for(auto& [num,freq] : mp){
            bucket[freq].push_back(num);
        }
        for(int i=n;i>=0;i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};