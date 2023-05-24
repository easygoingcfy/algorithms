//二维数组中的查找
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool Find(int target, vector<vector<int> > array) {
    int n = array.size();
    if (n == 0) return false;
    if (array[0].size() == 0) return false;
    int i = n - 1, j = 0;
    while (i >= 0 && j < n) {
      int num = array[i][j];
      if (num == target) {
        return true;
      } else if (num > target) {
        if (i > 0) {
            i--;
        } else {
            return false;
        }
      } else {
        if (j < n) {
            j++;
        } else {
            return false;
        }
      }
    }
    return false;
  }
};
