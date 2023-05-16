//拨钟问题
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> check(vector<int> move, vector<int> origin) {
  //对任意一种1，2,3移动的情况，计算是否有解
  move[4] = (4 - (move[1] + move[2] + origin[1]) % 4) % 4;            // A
  move[5] = (4 - (move[1] + move[2] + move[3] + origin[2]) % 4) % 4;  // B
  move[6] = (4 - (move[2] + move[3] + origin[3]) % 4) % 4;            // C
  move[7] = (4 - (move[1] + move[4] + move[5] + origin[4]) % 4) % 4;  // D
  move[9] =
      (4 - (move[1] + move[3] + move[5] + move[7] + origin[5]) % 4) % 4;  // E
  move[8] = (4 - (move[4] + move[7] + origin[7]) % 4) % 4;                // G

  // F H I
  int cur_f = (move[3] + move[5] + move[6] + move[9] + origin[6]) % 4;
  int cur_h = (move[5] + move[7] + move[8] + move[9] + origin[8]) % 4;
  int cur_i = (move[6] + move[8] + move[9] + origin[9]) % 4;
  if (cur_f == 0 && cur_h == 0 && cur_i == 0) {
    return move;
  }
  return {};
}

int main() {
  int count = 100;
  vector<int> origin(10, 0);
  vector<int> res(10, 0);
  for (int i = 1; i < 10; ++i) {
    cin >> origin[i];
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        vector<int> move(10, 0);
        move[1] = i;
        move[2] = j;
        move[3] = k;
        move = check(move, origin);
        if (!move.empty()) {
          int sum = accumulate(move.begin(), move.end(), 0);
          if (sum < count) {
            res.swap(move);
            count = sum;
          }
        }
      }
    }
  }
  for (int i = 1; i < 10; ++i) {
    while (res[i]--) {
      cout << i << " ";
    }
  }
  return 0;
}
