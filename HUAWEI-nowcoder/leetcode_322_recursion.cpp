//零钱兑换   递归思路， 会超时
#include <climits>
#include <vector>
using namespace std;

int MinCoin(vector<int>& coins, int amount) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;
  int res = INT_MAX;
  for (int i = 0; i < coins.size(); ++i) {
    int tmp = MinCoin(coins, amount - coins[i]);
    if (tmp != -1) {
      res = min(1 + tmp, res);
    }
  }
  return res == INT_MAX ? -1 : res;
}

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int res = MinCoin(coins, amount);
    return res;
  }
};