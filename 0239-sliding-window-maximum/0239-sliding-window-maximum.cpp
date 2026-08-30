class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq; //monotonic decreasing dq
        int left = 0;

        for(int right=0;right<nums.size();right++){
            //remove out of bound
            while(!dq.empty() && dq.front() <= right-k){
                dq.pop_front();
            }

            //maintain monotonic decreasing dq
            while(!dq.empty() && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }

            //add new ele
            dq.push_back(right);

            //add ans 
            if(right >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;

    }
};