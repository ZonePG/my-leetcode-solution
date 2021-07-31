class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<int> dp(prices.size(), 0);
    int min_prices = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < min_prices) {
        min_prices = prices[i];
      }
      dp[i] = prices[i] - min_prices;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
