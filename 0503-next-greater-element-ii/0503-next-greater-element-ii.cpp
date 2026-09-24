class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ng(n,-1);
        stack<int>st; //desc stack

        //l->r store indx
        for(int i=0;i<(n+n);i++){
            int idx = i%n;
            while(!st.empty() && nums[st.top()] < nums[idx]){
                ng[st.top()] = nums[idx];
                st.pop(); 
            }
            if(i<n) st.push(idx);
        }
        return ng;
    }
};