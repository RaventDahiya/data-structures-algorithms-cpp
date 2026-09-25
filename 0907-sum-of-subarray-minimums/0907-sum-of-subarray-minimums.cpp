class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        long long sum = 0;
        int n = arr.size();
        stack<int> st; // increasing stack
        vector<int> ns(n, n);
        vector<int> ps(n, -1);

        // next smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                ns[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // prev smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int left = i - ps[i];
            int right = ns[i] - i;

            sum = (sum + (1LL * num * left * right)%mod)%mod;
        }

        return sum;
    }
};