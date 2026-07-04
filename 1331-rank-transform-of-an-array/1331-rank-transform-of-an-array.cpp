class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &i : arr){
            pq.push(i);
        }
        unordered_map<int,int>mp;
        int j = 1;
        while(!pq.empty()){
            if(mp.count(pq.top())){
                pq.pop();
            }else{
                mp[pq.top()] = j++;
                pq.pop();
            }
            
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};