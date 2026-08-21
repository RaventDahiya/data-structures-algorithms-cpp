class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int maxProfit = 0;

        for(auto num : prices){
            minBuy = min(minBuy,num);
            maxProfit = max(maxProfit,num-minBuy);
        }
        return maxProfit;
    }
};