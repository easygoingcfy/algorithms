//动态规划
//要点：  dp[i][j] = dp[i -1][j - 1] if a[i] == b[j] else 0
//其中dp[i][j]表示以a[i] b[j]结尾的最长公共子串的长度
//若有多个，输出在较短串中最先出现的那个: 需要先遍历长的字符串
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) swap(a, b);
  int max_len = 0;
  string res;
  vector<vector<string>> dp(a.size() + 1, vector<string>(b.size() + 1));
  for (int i = 0; i <= a.size(); i++) dp[i][0] = "";
  for (int j = 0; j <= b.size(); j++) dp[0][j] = "";
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
      } else {
        dp[i][j] = "";
      }
      if (dp[i][j].length() > max_len) {
        max_len = dp[i][j].length();
        res = dp[i][j];
      }
    }
  }
  cout << res << endl;
  return 0;
}