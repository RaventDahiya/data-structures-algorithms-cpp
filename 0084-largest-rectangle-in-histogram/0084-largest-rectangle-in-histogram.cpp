class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int maxArea = 0;
        stack<int>st;

        for(int i=0;i<=n;i++){
            int ht = (i==n) ? 0 : h[i];

            while(!st.empty() && h[st.top()] >= ht){
                int nextSmall = i;
                int topHeight = h[st.top()]; st.pop();
                int prevSmall = st.empty() ? -1 : st.top();
                int area = topHeight * (nextSmall - prevSmall -1);
                maxArea = max(maxArea,area);
            }
            st.push(i);
        }

        return maxArea;
    }
};