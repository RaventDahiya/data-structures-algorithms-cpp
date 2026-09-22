class Solution {
public:
    bool isValid(vector<int>& b, int m, int k,int days){
        int bouquetsCount = 0;
        int flowerbBloom = 0;

        for(auto & f : b){
            if(f<=days){
                flowerbBloom++;
                if(flowerbBloom==k){
                    bouquetsCount++;
                    flowerbBloom=0;
                }
            }else{
                flowerbBloom=0;
            }
        }

        return bouquetsCount>=m;
    }
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        if(n < (long long)m * k) return -1;

        int l = 1;
        int r = *max_element(b.begin(),b.end());
        int minDays = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isValid(b,m,k,mid)){
                minDays = min(minDays,mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return minDays==INT_MAX ? -1 : minDays;
    }
};