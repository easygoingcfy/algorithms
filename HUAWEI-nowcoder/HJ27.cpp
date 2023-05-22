#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsBro(string s, string x) {
  if (s == x) return false;
  if (s.size() != x.size()) return false;
  sort(s.begin(), s.end());
  sort(x.begin(), x.end());
  return s == x;
}

int main() {
  int n, k;
  cin >> n;
  vector<string> array;
  vector<string> bros;
  string s, x;
  while (n--) {
    cin >> s;
    array.emplace_back(s);
  }
  cin >> x >> k;
  for (string s : array) {
    if (IsBro(s, x)) {
      bros.emplace_back(s);
    }
  }
  sort(bros.begin(), bros.end());
  cout << bros.size() << endl;
  if (k < bros.size()) {
    cout << bros[k - 1] << endl;
  }
  return 0;
}