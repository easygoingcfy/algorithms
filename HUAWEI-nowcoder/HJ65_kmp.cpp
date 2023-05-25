//此题不能用kmp，因为kmp是完全匹配，公共子串不是完全匹配
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> BuildNext(string s) {
  vector<int> next(s.size(), 0);
  int i = 1;
  int prefix_len = 0;
  while (i < s.size()) {
    if (s[prefix_len] == s[i]) {
      prefix_len++;
      next[i] = prefix_len;
      i++;
    } else if (prefix_len > 0) {
      prefix_len = next[prefix_len - 1];
    } else {
      next[i] = 0;
      i++;
    }
  }
  return next;
}

int main() {
  string a, b;
  cin >> a >> b;
  int max_len = 0;
  if (a.size() > b.size()) {
    swap(a, b);
  }
  auto next = BuildNext(a);
  int i = 0, j = 0;
  while (i < b.size()) {
    if (b[i] == a[j]) {
      i++;
      j++;
    } else if (j > 0) {
      j = next[j - 1];
    } else {
      i++;
    }
    max_len = max(max_len, j);
  }
  string res = a.substr(0, max_len);
  cout << res << endl;
}