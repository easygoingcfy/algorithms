//有重复字符串的排列组合
//深搜与减枝， 还未掌握
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> permutation(string S) {
    vector<string> res;
    vector<bool> is_null(S.size(), false);
    string str;
    DFS(S, str, res, is_null);
    return res;
  }

  void DFS(string S, string& str, vector<string>& res, vector<bool>& is_null) {
    if (str.size() == S.size()) {
      res.push_back(str);
      return;
    }
    map<char, int> dup;
    for (int i = 0; i < S.length(); ++i) {
      if (is_null[i]) {
        continue;
      }
      if (dup[S[i]]) continue;
      dup[S[i]]++;
      str += S[i];
      is_null[i] = true;
      DFS(S, str, res, is_null);
      is_null[i] = false;
      str.pop_back();
    }
    return;
  }
};

int main() {
  auto so = Solution();
  string s = "ab";
  auto res = so.permutation(s);
  for (auto s : res) {
    cout << s << endl;
  }
}