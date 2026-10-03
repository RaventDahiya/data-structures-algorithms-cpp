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

    vector<int> nextLargest(vector<int>& arr) {
        int n = arr.size();
        vector<int> ns(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                ns[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return ns;
    }

    vector<int> prevLargest(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ps;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> ns = nextSmall(nums);
        vector<int> ps = prevSmall(nums);
        vector<int> pg = prevLargest(nums);
        vector<int> ng = nextLargest(nums);

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long leftMin = i - ps[i];
            long long rightMin = ns[i] - i;
            minSum += 1LL * nums[i] * leftMin * rightMin;

            long long leftMax = i - pg[i];
            long long rightMax = ng[i] - i;
            maxSum += 1LL * nums[i] * leftMax * rightMax;

        }

        return maxSum-minSum;
    }
};