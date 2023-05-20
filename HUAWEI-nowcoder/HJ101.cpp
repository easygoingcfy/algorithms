#include <iostream>
#include <vector>

using namespace std;

void Swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

bool IsBigger(int a, int b, int key) {
  if (key == 0)
    return a >= b;
  else {
    return a <= b;
  }
}

void QuickSort(vector<int>& array, int s, int e, int key) {
  if (s >= e) {
    return;
  }
  int left = s, right = e;
  int value = array[left];
  while (left != right) {
    while (right > left && IsBigger(array[right], value, key)) right--;
    Swap(array[left], array[right]);
    while (left < right && !IsBigger(array[left], value, key)) left++;
    Swap(array[left], array[right]);
  }
  QuickSort(array, s, left, key);
  QuickSort(array, left + 1, e, key);
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> array(n, 0);
    int key;
    for (int i = 0; i < n; ++i) cin >> array[i];
    cin >> key;
    QuickSort(array, 0, array.size() - 1, key);
    for (auto num : array) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}