class Solution {
public:
    vector<int> nseHelper(vector<int>& heights, int& n) {
        vector<int> nse(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }
    vector<int> pseHelper(vector<int>& heights, int& n) {
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i <n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = nseHelper(heights, n);
        vector<int> pse = pseHelper(heights, n);

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};