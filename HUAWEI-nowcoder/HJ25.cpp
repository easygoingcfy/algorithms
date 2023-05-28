//数据分类处理
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

bool Include(int i, int r) {
  //计算i是否包含r
  string si = to_string(i);
  string sr = to_string(r);
  return si.find(sr) != string::npos;
}

int main() {
  int r_len, i_len;
  cin >> i_len;
  vector<int> arr_i(i_len);
  for (int i = 0; i < i_len; ++i) {
    cin >> arr_i[i];
  }
  cin >> r_len;
  vector<int> arr_r;
  set<int> dup;
  for (int i = 0; i < r_len; ++i) {
    int value;
    cin >> value;
    if (dup.find(value) != dup.end()) {
      continue;
    }
    dup.insert(value);
    arr_r.emplace_back(value);
  }
  sort(arr_r.begin(), arr_r.end());
  map<int, vector<pair<int, int>>> res;
  for (int i = 0; i < arr_r.size(); ++i) {
    for (int j = 0; j < arr_i.size(); ++j) {
      if (Include(arr_i[j], arr_r[i])) {
        pair<int, int> tmp = {j, arr_i[j]};
        res[arr_r[i]].emplace_back(tmp);
      }
    }
  }
  int total = 0;
  for (auto iter = res.begin(); iter != res.end(); iter++) {
    total += 1 + 1 + iter->second.size() * 2;
  }
  cout << total << " ";
  for (auto iter = res.begin(); iter != res.end(); iter++) {
    cout << iter->first << " " << iter->second.size() << " ";
    for (auto x : iter->second) {
      cout << x.first << " " << x.second << " ";
    }
  }
  cout << endl;
  return 0;
}