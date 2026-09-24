class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++) temp.push_back(nums[i]);
        for(int i=0;i<nums.size();i++) temp.push_back(nums[i]);

        int n = temp.size();
        vector<int>ng(n,-1);
        stack<int>st; //desc stack

        //l->r store indx
        for(int i=0;i<n;i++){
            while(!st.empty() && temp[st.top()] < temp[i]){
                ng[st.top()] = temp[i];
                st.pop(); 
            }
            st.push(i);
        }
        ng.resize(nums.size());
        return ng;
    }
};