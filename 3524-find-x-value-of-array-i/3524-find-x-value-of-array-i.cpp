class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>result(k,0);
        vector<long long>prevCount(k,0);

        for(int i=0;i<nums.size();i++){
            vector<long long>currCount(k,0);
            currCount[nums[i]%k]++;
            for(int oldRem=0;oldRem<=k-1;oldRem++){
                long long newRem = ((long long)oldRem*nums[i]%k)%k;
                currCount[newRem] += prevCount[oldRem];
            }
            prevCount = std::move(currCount);
            for(int x=0;x<=k-1;x++){
                result[x]+=prevCount[x];
            }
        }
        return result;
    }
};