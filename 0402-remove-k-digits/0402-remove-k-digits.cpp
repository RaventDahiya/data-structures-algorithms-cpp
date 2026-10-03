class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if (k >= n)
            return "0";

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (k > 0 &&
                   !st.empty() &&
                   num[st.top()] > num[i]) {

                st.pop();
                k--;
            }

            st.push(i);
        }

        // Important:
        // If k is still remaining, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";

        while (!st.empty()) {
            ans += num[st.top()];
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int i = 0;

        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};