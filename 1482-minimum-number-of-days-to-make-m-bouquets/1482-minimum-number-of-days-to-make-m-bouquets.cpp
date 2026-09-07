class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k,int days){
        int totalFlower = 0;
        int adjFlower = 0;
        for(auto it : bloomDay){
            if(days >= it){ //flower bloomed
                adjFlower++;
                if(adjFlower == k){ //flower made
                    totalFlower++;
                    adjFlower = 0;
                    if(totalFlower==m) return true;
                }
            }else{
                adjFlower = 0;
            }
        }
        if(totalFlower>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;

        int left = 0; 
        int right = INT_MIN;

        for(auto it : bloomDay){
            right = max(right,it);
        }

        int minDay = right;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(isValid(bloomDay,m,k,mid)){
                minDay = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return minDay;
    }
};