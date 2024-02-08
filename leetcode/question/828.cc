#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  Solution s;
  string input;
  while (true) {
    cin >> input;
    cout << s.uniqueLetterString(input) << endl;
  }
}

class Solution {
 public:
  int uniqueLetterString(string s) {
    int res = 0;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
      for (int sub_len = 1; sub_len < len - i; ++sub_len) {
        res += getUniqueChar(s.substr(i, sub_len));
      }
    }
    return res;
  }

  int getUniqueChar(string s) {
    unordered_map<char, int> cmap;
    int result = 0;
    for (auto const& c : s) {
      cmap[c]++;
    }
    for (auto const& pair : cmap) {
      if (pair.second == 1) {
        result++;
      }
    }
    return result;
  }
};
