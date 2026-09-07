class Solution {
public:
    bool isValid(vector<int>& piles, int h,int k){
        long long timeTaken = 0;
        for(auto it : piles){

                timeTaken += it/k;
                if(it%k) timeTaken++;
            
        }
        if(timeTaken<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; //min speed
        int right = INT_MIN; //maxSpeed

        for(auto it : piles){
            right = max(right,it);
        }

        int k = right;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(isValid(piles,h,mid)){
                k = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return k;
    }
};