class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;

        // Add all positive differences
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};