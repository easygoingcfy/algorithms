class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // dp[i]: sell at day i
    vector<int> dp(prices.size());
    dp[0] = 0;
    int res = 0;
    int min_price = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      min_price = min(min_price, prices[i - 1]);
      dp[i] = prices[i] - min_price;
      res = max(res, dp[i]);
    }
    return res;
  }
};