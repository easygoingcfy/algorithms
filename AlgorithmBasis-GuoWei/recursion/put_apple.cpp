#include <iostream>

using namespace std;

int ways(int m, int n) {
  if (n > m) {
    return ways(m, m);
  }
  if (m == 0) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }
  return ways(m - n, n) + ways(m, n - 1);
}

int main() {
  int t;
  int m, n;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    cout << ways(m, n) << endl;
  }
  return 0;
}