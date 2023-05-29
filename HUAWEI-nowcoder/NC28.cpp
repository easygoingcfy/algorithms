//最小覆盖子串
#include <climits>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  /**
   *
   * @param S string字符串
   * @param T string字符串
   * @return string字符串
   */
  string minWindow(string S, string T) {
    // write code here
    map<char, int> my_map, window;
    int valid = 0;
    string res;
    int min_len = INT_MAX;
    for (auto c : T) {
      my_map[c]++;
    }
    int left = 0, right = 0;
    while (right < S.size()) {
      char c = S[right];
      right++;
      if (my_map.count(c)) {
        window[c]++;
        if (my_map[c] == window[c]) {
          valid++;
        }
      }
      while (valid == my_map.size()) {
        if (right - left < min_len) {
          min_len = right - left;
          res = S.substr(left, right - left);
        }
        c = S[left];
        left++;
        if (my_map.count(c)) {
          if (my_map[c] == window[c]) {
            valid--;
          }
          window[c]--;
        }
      }
    }
    return res;
  }
};

int main() {
  auto so = Solution();
  string s = "XDOYEZODEYXNZ";
  string t = "XYZ";
  string res = so.minWindow(s, t);
  cout << res << endl;
  return 0;
}