#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> str_list(n);
  for (int i = 0; i < n; ++i) {
    cin >> str_list[i];
  }
  sort(str_list.begin(), str_list.end());
  for (auto s: str_list) {
    cout << s << endl;
  }
  return 0;
}