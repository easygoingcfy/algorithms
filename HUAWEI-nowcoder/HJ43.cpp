//迷宫问题
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<pair<int, int>>& res, vector<vector<int>>& maze,
         vector<pair<int, int>>& cur, int x, int y) {
  int n = maze.size();
  int m = maze[0].size();
  if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != 0) {
    return;
  }
  maze[x][y] = 1;
  cur.emplace_back(x, y);
  if (x == n - 1 && y == m - 1) {
    res = cur;
  }
  DFS(res, maze, cur, x + 1, y);
  DFS(res, maze, cur, x - 1, y);
  DFS(res, maze, cur, x, y + 1);
  DFS(res, maze, cur, x, y - 1);
  cur.pop_back();
  maze[x][y] = 0;
}

int main() {
  vector<pair<int, int>> cur, res;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> maze(n, vector<int>(m));
  vector<vector<int>> visited(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> maze[i][j];
    }
  DFS(res, maze, cur, 0, 0);
  for (auto step : res) {
    cout << '(' << step.first << ',' << step.second << ')' << endl;
  }
  return 0;
}