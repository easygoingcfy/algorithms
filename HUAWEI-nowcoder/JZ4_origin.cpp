//从左上角开始搜索  尚未成功

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
    int i = 0, j = 0;
    while (i < n && j < n) {
      int num = array[i][j];
      if (num == target) {
        return true;
      } else if (target < num) {
        return false;
      } else {
        int right = 0, down = 0;
        if (i + 1 < n) down = array[i + 1][j];
        if (j + 1 < n) right = array[i][j + 1];
        if (down == target || right == target) return true;
        if (down > right) {
          if (target < right) return false;
          if (target > right && target < down) {
            if (j + 1 < n) {
              j++;
            } else {
              return false;
            }
          } else {
            if (i + 1 < n) {
              i++;
            } else {
              return false;
            }
          }
        } else {
          if (target < down) return false;
          if (target > down && target < right) {
            if (i + 1 < n) {
              i++;
            } else {
              return false;
            }
          } else {
            if (j + 1 < n) {
              j++;
            } else {
              return false;
            }
          }
        }
      }
    }
    return false;
  }
};

int main() {
    int target = 7;
    vector<vector<int>> array = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15},
    };
    auto so = Solution();
    so.Find(target, array);
}