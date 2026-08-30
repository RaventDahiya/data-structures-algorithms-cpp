class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int minLen = INT_MAX;
        for (int i = 0; i <= n; i++) {
            // check current i-front >= k
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            // maintain incraseing oder of dq
            while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};