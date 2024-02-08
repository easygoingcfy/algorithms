#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isCousins(TreeNode *root, int x, int y) {
        x_ = x;
        y_ = y;
        x_found = false, y_found = false;
        queue<pair<TreeNode*, int>> my_queue;
        my_queue.emplace(root, 0);
        while (!my_queue.empty()) {
            auto ele = my_queue.front();
            auto node = ele.first;
            auto depth = ele.second;
            if (node->left) my_queue.emplace(node->left, depth + 1);
            if (node->right) my_queue.emplace(node->right, depth + 1);
            if (node->val == x) {
                x_depth = depth;
                x_parent
            }
            
        }
        dfs(root, 0, nullptr);
        return x_parent != y_parent && x_depth == y_depth;
    }

   private:
    TreeNode *x_parent, *y_parent;
    int x_depth, y_depth;
    int x_, y_;
    // optimize
    bool x_found, y_found;

    void dfs(TreeNode *node, int depth, TreeNode *parent) {
        if (!node) {
            return;
        }
        depth++;
        if (node->val == y_) {
            y_depth = depth;
            y_parent = parent;
            y_found = true;
        }
        if (node->val == x_) {
            x_depth = depth;
            x_parent = parent;
            x_found = true;
        }
        if (x_found && y_found) return;
        dfs(node->left, depth, node);
        dfs(node->right, depth, node);
    }
};`