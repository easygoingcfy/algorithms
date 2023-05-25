//组合
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<bool> valid(n, true);
        vector<int> cur;
        DFS(res, n, k, cur, valid);
        return res;
    }

    void DFS(vector<vector<int>>& res, int n, int k, vector<int>& cur, vector<bool>& valid) {
        if (cur.size() == k) {
            res.emplace_back(cur);
            return;
        }
        int i = 0;
        if (cur.size() > 0) {
            i = cur[cur.size() - 1];
        }
        for (; i < n; i++) {
            if (!valid[i]) {
                continue;
            }
            valid[i] = false;
            cur.emplace_back(i + 1);
            DFS(res, n, k, cur, valid);
            cur.pop_back();
            valid[i] = true;
        }
    }
};