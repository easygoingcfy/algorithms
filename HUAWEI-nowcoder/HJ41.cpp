#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> weight(n), nums(n);
  int total = 0;
  for (int i = 0; i < n; ++i) cin >> weight[i];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    total += nums[i] * weight[i];
  }
  vector<bool> dp(total + 1, false);
  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < nums[i]; ++j) {
      for (int k = total; k >= weight[i]; k--) {
        if (dp[k - weight[i]]) {
          dp[k] = true;
        }
      }
    }
  }
  int res = 0;
  for (auto b : dp) {
    if (b) {
      res++;
    }
  }
  cout << res << endl;
}
