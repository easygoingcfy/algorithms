//从上到下打印二叉树
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> col;
    bool order = true;
    if (!root) return res;
    col.push(root);
    while (!col.empty()) {
      int len = col.size();
      vector<int> cur;
      for (int i = 0; i < len; ++i) {
        auto top = col.front();
        cur.emplace_back(top->val);
        col.pop();
        if (top->left) col.push(top->left);
        if (top->right) col.push(top->right);
      }
      if (!order) {
        reverse(cur.begin(), cur.end());
      }
      res.emplace_back(cur);
      order = !order;
    }
    return res;
  }
};