class Solution {
public:
    vector<int> nextSmall(vector<int>& arr) {
        int n = arr.size();
        vector<int> ns(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                ns[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return ns;
    }

    vector<int> prevSmall(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ps;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> ns = nextSmall(arr);
        vector<int> ps = prevSmall(arr);

        long long mod = 1e9 + 7;
        long long total = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long left = i - ps[i];
            long long right = ns[i] - i;

            long long contribution =
                (1LL * arr[i] * left % mod * right) % mod;

            total = (total + contribution) % mod;
        }

        return total;
    }
};