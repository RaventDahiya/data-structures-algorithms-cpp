class Solution {
public:
    struct custom{
        unordered_map<int,int>&mp;
        custom(unordered_map<int,int>&mapRef) : mp(mapRef) {}
        bool operator()(int a, int b){
            return mp[a] > mp[b];
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        priority_queue<int,vector<int>,custom>pq((custom(mp)));

        for(auto&[key,value]:mp){
            if(pq.size()<k) pq.push(key);
            else{
                int front = pq.top();
                if(mp[front] < value){
                    pq.pop();
                    pq.push(key);
                }
            }
        }
        vector<int>ans;
        while(k){
            ans.push_back(pq.top());
            pq.pop();
            k--;
        }
        return ans;
    }
};