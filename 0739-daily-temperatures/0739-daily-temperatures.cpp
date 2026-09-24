class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ng(n,0);
        stack<int>st;//decr stack

        //store index -> next g -> l->r
        for(int i=0;i<n;i++){
            while(!st.empty() && temp[st.top()] < temp[i]){
                ng[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ng;
    }
};