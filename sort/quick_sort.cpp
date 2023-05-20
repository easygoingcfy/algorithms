//快速排序
#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void QuickSort(vector<int>& array, int s, int e) {
  if (s >= e) {
    return;
  }
  int left = s, right = e;
  int value = array[s];
  while (left != right) {
    //从右边找一个小于value的
    while (right > left && array[right] >= value) {
      right--;
    }
    swap(array[left], array[right]);
    while (left < right && array[left] <= value) {
      left++;
    }
    swap(array[left], array[right]);
  }
  QuickSort(array, s, left);
  QuickSort(array, left + 1, e);
}

template <typename T>
void print_iterable(T iterable) {
  for (auto element : iterable) {
    cout << element << " ";
  }
  cout << endl;
}

int main() {
  srand(time(NULL));
  vector<int> array(100);
  cout << "original array:" << endl;
  for (int i = 0; i < 100; ++i) {
    array[i] = rand() % 99 + 1;
    cout << array[i] << " ";
  }
  cout << endl << "after quick sort:" << endl;
  QuickSort(array, 0, array.size() - 1);
  print_iterable(array);
  return 0;
}