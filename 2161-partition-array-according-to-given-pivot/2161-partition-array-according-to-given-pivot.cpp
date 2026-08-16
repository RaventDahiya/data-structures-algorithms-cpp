class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int i = 0;
        int j = n - 1;
        for(auto& num : nums){
            if(num < pivot){
                ans[i++] = num;
            }else if(num > pivot){
                ans[j--] = num;
            }
        }
        while(i<=j){
            ans[i++] = pivot;
        }
        reverse(ans.begin()+j+1,ans.end());
        return ans;
    }
};