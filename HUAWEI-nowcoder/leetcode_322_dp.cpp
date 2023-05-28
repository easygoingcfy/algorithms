//零钱兑换
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= amount; ++i) {
      for (auto coin : coins) {
        if (i >= coin && dp[i - coin] != INT_MAX) dp[i] = min(dp[i - coin] + 1, dp[i]);
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};