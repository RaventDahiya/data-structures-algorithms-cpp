class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            //remove out of the window ele
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //maintain max dq
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            //add new ele
            dq.push_back(i);
            //store ans
            if(i >= k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};