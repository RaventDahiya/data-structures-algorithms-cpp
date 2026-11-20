class Solution {
public:
    int n;
    vector<vector<int>>memo;
    int findMethod(vector<int>&nums,int str,int tar){
        int j = lower_bound(begin(nums)+str,end(nums),tar) - begin(nums);
        if(j<n && nums[j]==tar){
            return j;
        }
        return -1;
    }
    int solve(int i,int inc,vector<int>&nums){
        if(memo[i][inc]!=-1) return memo[i][inc];
        int currVal = nums[i]+inc;
        int len = 1;

        int j = findMethod(nums,i+1,currVal+1);
        if(j!=-1){
            len = max(len,1+solve(j,0,nums));
        }

        j = findMethod(nums,i+1,currVal);
        if(j!=-1){
            len = max(len,1+solve(j,1,nums));
        }

        return  memo[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        memo.assign(n+1,vector<int>(2,-1));
        int result = 1;
        for(int i=0;i<n;i++){
            result = max({result,solve(i,0,nums),solve(i,1,nums)});
        }

        return result;
    }
};