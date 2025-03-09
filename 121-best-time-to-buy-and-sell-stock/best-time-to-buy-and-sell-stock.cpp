class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int minStock = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maximumProfit = max(maximumProfit, prices[i] - minStock);
            minStock = min(minStock, prices[i]);
        }
        return maximumProfit;
    }
};