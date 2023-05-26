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
    if (root == nullptr) return res;
    col.push(root);
    while (!col.empty()) {
      vector<int> cur;
      int n = col.size();
      for (int i = 0; i < n; ++i) {
        auto top = col.front();
        cur.emplace_back(top->val);
        if (top->left != nullptr) col.push(top->left);
        if (top->right != nullptr) col.push(top->right);
        col.pop();
      }
      res.emplace_back(cur);
    }
    return res;
  }
};



