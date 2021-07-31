class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int min_prices = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < min_prices) {
        min_prices = prices[i];
      }
      int profit = prices[i] - min_prices;
      if (max_profit < profit)
        max_profit = profit;
    }
    return max_profit;
  }
};
