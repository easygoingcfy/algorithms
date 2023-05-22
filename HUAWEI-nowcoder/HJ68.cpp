#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, label;
  cin >> n >> label;
  vector<pair<string, int>> array(n);
  for (int i = 0; i < n; i++) {
    cin >> array[i].first >> array[i].second;
  }
  if (label == 1) {
    stable_sort(
        array.begin(), array.end(),
        [](pair<string, int> a, pair<string, int> b) -> bool { return a.second < b.second; });
  } else {
    stable_sort(
        array.begin(), array.end(),
        [](pair<string, int> a, pair<string, int> b) -> bool { return a.second > b.second; });
  }

  for (auto ele : array) {
    cout << ele.first << " " << ele.second << endl;
  }
  return 0;
}