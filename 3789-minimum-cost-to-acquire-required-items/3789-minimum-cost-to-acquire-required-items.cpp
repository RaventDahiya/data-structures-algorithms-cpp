class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(cost1+cost2 <= costBoth){
            ans = (1LL*need1*cost1) + (1LL*need2*cost2);
        }else{
            
                int minNeed = min(need1,need2);
                ans += 1LL*minNeed*costBoth;
                need1 -= minNeed;
                need2 -= minNeed;
                if(need1 > 0){
                    ans += 1LL*need1*min(cost1,costBoth);
                }else{
                    ans += 1LL*need2*min(cost2,costBoth);
                }
            
        }
        return ans;
    }
};