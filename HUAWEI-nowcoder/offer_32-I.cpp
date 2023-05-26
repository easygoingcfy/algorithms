//从上到下打印二叉树
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  vector<int> levelOrder(TreeNode* root) {
    queue<TreeNode*> col;
    vector<int> res;
    if (root == nullptr) return res;
    col.push(root);
    while (!col.empty()) {
      for (int i = 0; i < col.size(); ++i) {
        auto top = col.front();
        res.emplace_back(top->val);
        col.pop();
        if (top->left != nullptr) col.push(top->left);
        if (top->right != nullptr) col.push(top->right);
      }
    }
    return res;
  }
};