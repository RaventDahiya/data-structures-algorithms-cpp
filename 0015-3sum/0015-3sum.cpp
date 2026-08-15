class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>>st;
        sort(arr.begin(),arr.end());
        int n = arr.size();

        for(int i=0;i<=n-3;i++){
            int l = i+1;
            int r = n -1;
            int target = -(arr[i]);
            while(l<r){
                int sum = arr[l] + arr[r];
                if(sum == target) {
                    st.insert({arr[i],arr[l],arr[r]});
                    l++; r--;
                }else if(sum < target) l++;
                else r--;
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};