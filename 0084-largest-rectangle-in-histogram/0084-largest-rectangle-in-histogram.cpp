class Solution {
public:
    vector<int> prevSmall(vector<int>& h){
        int n = h.size();
        vector<int>ps(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ps;
    }
    vector<int> nextSmall(vector<int>& h){
        int n = h.size();
        vector<int>ns(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()] > h[i]){
                ns[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return ns;

    }
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int>ps = prevSmall(h);
        vector<int>ns = nextSmall(h);

        int ans = 0;

        for(int i=0;i<n;i++){
            int width = ns[i] - ps[i] - 1;
            int area = h[i] * width;
            ans = max(ans,area);
        }

        return ans;
    }
};