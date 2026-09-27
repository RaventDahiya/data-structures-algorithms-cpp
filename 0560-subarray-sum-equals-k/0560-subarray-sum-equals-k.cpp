class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        long long sum = 0;
        int total = 0;
        for(auto &num : nums){
            sum += num;
            if(mp.count(sum-k)){
                total += mp[sum-k];
            }
            mp[sum]++;
        }
        return total;
    }
};