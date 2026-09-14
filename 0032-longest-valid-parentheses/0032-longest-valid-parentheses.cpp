class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        int prev = s.size();
        while(!st.empty()){
            int top = st.top(); st.pop();
            maxLen = max(maxLen,prev-top-1);
            prev = top; 
        }
        
        maxLen = max(maxLen, prev);
        return maxLen;
    }
};
