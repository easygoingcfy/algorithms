#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, key;
  while (cin >> n) {
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
      cin >> array[i];
    }
    cin >> key;
    if (key == 0) {
      sort(array.begin(), array.end());
    } else {
      sort(array.begin(), array.end(), greater<int>());
    }
    for (auto num : array) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
