#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> BuildNext(string s) {
    pass;
}

int main() {
  int n, label;
  cin >> n >> label;
  vector<pair<string, int>> array(n);
  for (int i = 0; i < n; i++) {
    cin >> array[i].first >> array[i].second;
  }

  for (auto ele : array) {
    cout << ele.first << " " << ele.second << endl;
  }
  return 0;
}