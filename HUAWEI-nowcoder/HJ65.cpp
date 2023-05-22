//TODO: 动态规划
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string a, b;
  string res = "";
  vector<int> next;
  cin >> a >> b;
  if (a.size() > b.size()) {
    swap(a, b);
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = i; j < a.size(); j++) {
      string tmp = a.substr(i, j - i + 1);
      if (b.find(tmp) != string::npos && tmp.length() > res.length()) {
        res = tmp;
      }
    }
  }
  cout << res << endl;
}