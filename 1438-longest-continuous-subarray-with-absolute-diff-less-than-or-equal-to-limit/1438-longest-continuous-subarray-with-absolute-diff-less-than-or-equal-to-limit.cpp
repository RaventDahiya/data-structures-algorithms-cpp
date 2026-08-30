class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxdq,mindq;
        int left = 0,maxLen = 0;

        for(int right=0;right<nums.size();right++){
            //maintain max and min dq
            while(!maxdq.empty() && nums[maxdq.back()] < nums[right]){
                maxdq.pop_back();
            }
            while(!mindq.empty() && nums[mindq.back()] > nums[right]){
                mindq.pop_back();
            }
            maxdq.push_back(right); mindq.push_back(right);
            //shrink window
            while(nums[maxdq.front()] - nums[mindq.front()] > limit){
                if(maxdq.front() == left) maxdq.pop_front();
                if(mindq.front() == left) mindq.pop_front();
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};