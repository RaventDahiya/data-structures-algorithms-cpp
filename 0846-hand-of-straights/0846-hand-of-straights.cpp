class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0 ) return false;
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(auto &i : hand){
            minHeap.push(i);
        }

        while(!minHeap.empty()){
            vector<int>temp;
            while(maxHeap.size()!= groupSize){
                if(minHeap.empty()) return false;
                int minFront = minHeap.top(); minHeap.pop();
                if(maxHeap.empty()){
                    maxHeap.push(minFront);
                }else if(maxHeap.top() + 1 != minFront){
                    temp.push_back(minFront);
                }else{
                    maxHeap.push(minFront);
                }
            }
            maxHeap = priority_queue<int>();
            for(auto &i : temp){
                minHeap.push(i);
            }
        }
        return true;
    }
};