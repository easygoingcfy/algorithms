//腐烂的橘子
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    int remain = 0;
    vector<int> dir_x = {0, 1, 0, -1};
    vector<int> dir_y = {1, 0, -1, 0};
    queue<pair<int, int>> col;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2) {
          col.push(pair<int, int>(i, j));
        } else if (grid[i][j] == 1) {
          remain++;
        }
      }
    }
    while (!col.empty()) {
      if (remain == 0) return res;
      int size = col.size();
      for (int i = 0; i < size; ++i) {
        auto top = col.front();
        col.pop();
        for (int step = 0; step < 4; ++step) {
          int x = top.first + dir_x[step];
          int y = top.second + dir_y[step];
          if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
          grid[x][y] = 2;
          col.push({x, y});
          remain--;
        }
      }
      res++;
    }
    return remain == 0 ? res : -1;
  }
};

int main() {
    auto so = Solution();
    vector<vector<int>> grid = {
        {1, 2},
    };
    int res = so.orangesRotting(grid);
    return 0;
}