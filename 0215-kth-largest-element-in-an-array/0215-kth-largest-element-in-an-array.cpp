class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        for(int i=0;i<k && i<n;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            int curr = nums[i];
            if(pq.top() < curr){
                pq.pop();
                pq.push(curr);
            }
        }
        return pq.top();
    }
};