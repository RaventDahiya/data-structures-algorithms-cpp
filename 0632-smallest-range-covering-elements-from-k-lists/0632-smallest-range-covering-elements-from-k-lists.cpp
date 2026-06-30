class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int miniDiff = INT_MAX;
        int maxi = INT_MIN;
        vector<int> ans = {-1, -1};
        priority_queue<tuple<int, int, int>, 
                        vector<tuple<int, int, int>>,
                        greater<tuple<int, int, int>>> pq;

        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        while(!pq.empty()){
            auto [value, row, col] = pq.top();
            pq.pop();

            int diff = maxi - value;
            if(diff < miniDiff){
                miniDiff = diff;
                ans = {value,maxi};
            }
            int n = nums[row].size();
            if(col + 1 < n){
                maxi = max(maxi,nums[row][col+1]);
                pq.push({nums[row][col+1],row,col+1});
            }else{
                break;
            }
        }
        return ans;
    }
};