class Solution {
public:
    bool isValid(vector<int>& piles, int h,int k){
        long long totalHr = 0;
        for(auto &num : piles){
            totalHr += num/k;
            if(num%k) totalHr++;
        }
        return totalHr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int k = INT_MAX;
        while(l<=r){
            int m = l + (r-l)/2;
            if(isValid(piles,h,m)){
                k = min(k,m);
                r = m -1;
            }else{
                l = m + 1;
            }
        }
        return k;
    }
};