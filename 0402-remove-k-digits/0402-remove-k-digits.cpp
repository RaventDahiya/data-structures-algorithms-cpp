class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        unordered_set<int>notInclude;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && num[st.top()] > num[i]) {
                notInclude.insert(st.top());
                if(notInclude.size()==k) break;
                st.pop();
            }
            if(notInclude.size()==k) break;
            st.push(i);
        }

        while (!st.empty() && notInclude.size() < k) {
            notInclude.insert(st.top());
            st.pop();
        }

        string ans = "";
        for(int i=0;i<n;i++){
            if(!notInclude.count(i)){
                if(ans.size()==0 && num[i]=='0') continue;
                ans += num[i];
            }
        }
        return ans=="" ? "0" : ans;
    }
};