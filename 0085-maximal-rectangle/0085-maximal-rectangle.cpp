class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> ns(n, n);
        vector<int> ps(n, -1);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                ns[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = h[i] * ((ns[i] - i) + (i - (ps[i] + 1)));
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>h(m,0);
        int maxRec = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0') h[j]=0;
                else h[j] += 1;
            }
            maxRec = max(maxRec,largestRectangleArea(h));
        }
        return maxRec;
    }
};