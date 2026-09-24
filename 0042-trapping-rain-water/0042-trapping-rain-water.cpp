class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = h[0];
        rightMax[n - 1] = h[n - 1];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(h[i], leftMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(h[i], rightMax[i + 1]);
        }

        int trapedWater = 0;
        for(int i=0;i<n;i++){
            trapedWater += min(leftMax[i],rightMax[i]) - h[i];
        }

        return trapedWater;
    }
};