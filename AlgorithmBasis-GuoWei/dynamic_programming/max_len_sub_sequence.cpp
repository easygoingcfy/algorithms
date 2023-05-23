//最长递增子序列
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> array(N);
  int max_len = 0;
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }
  vector<int> dp(N, 1);
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
        if (array[j] < array[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
  }
  max_len = *max_element(dp.begin(), dp.end());
  cout << max_len;
}