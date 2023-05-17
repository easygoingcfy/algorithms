//归并排序
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void MergeSort(vector<int>& array, int begin, int end);
void Merge(vector<int>& array, int a, int b, int c);

void MergeSort(vector<int>& array, int begin, int end) {
  if (begin < end) {
    vector<int> res;
    int mid = (begin + end / 2) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
  }
}

void Merge(vector<int>& array, int a, int b, int c) {
  vector<int> tmp(500);
  int first = a, second = b + 1;
  int index = 0;
  while (first <= b && second <= c) {
    if (array[first] < array[second]) {
      tmp[index++] = array[first++];
    } else {
      tmp[index++] = array[second++];
    }
  }
  while (first <= b) {
    tmp[index++] = array[first++];
  }
  while (second <= c) {
    tmp[index++] = array[second++];
  }
  for (int i = 0; i < c - a + 1; ++i) {
    array[a + i] = tmp[i];
  }
}