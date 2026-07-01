class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(auto &ch : tasks){
            mp[ch-'A']++;
        }
        priority_queue<int>pq;
        for(auto &freq : mp){
            if(freq>0) pq.push(freq);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    auto front = pq.top(); pq.pop();
                    front--;
                    temp.push_back(front);
                }
            }
            for(auto &freq : temp){
                if(freq>0) pq.push(freq);
            }
            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};