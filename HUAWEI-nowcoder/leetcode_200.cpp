//明显的深搜
#include <vector>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int x, int y) {
      int m = grid.size();
      int n = grid[0].size();
      if (x < 0 || y < 0 || x >= m || y >=n || grid[x][y] == '0') {
        return;
      }
      grid[x][y] = '0';
      DFS(grid, x + 1, y);
      DFS(grid, x - 1, y);
      DFS(grid, x, y + 1);
      DFS(grid, x, y - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
      int res = 0;   
      int m = grid.size();
      int n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                DFS(grid, i, j);
                res++;
            }
        }
      }
      return res;
    }
};