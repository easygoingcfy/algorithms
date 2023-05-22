#include <cmath>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param s string字符串
   * @return int整型
   */
  int StrToInt(string s) {
    // write code here
    int res = 0;
    int i = 0;
    int symbol = 1;
    while (i < s.size()) {
        if (s[i] == ' ') {
            i++;
        } else {
            break;
        }
    }
    if (isalpha(s[i])) return 0;
    if (s[i] == '+' || s[i] == '-') {
      symbol = (s[i] == '+') ? 1 : -1;
      i++;
    }
    while (i < s.length() && isdigit(s[i])) {
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
        return INT_MAX;
      }
      if (res < INT_MIN / 10 || (res == INT_MIN / 10 && s[i] - '0' > -(INT_MIN) % 10))  {
        return INT_MIN;
      }
      res = res * 10 + symbol * (s[i] - '0');
      i++;
    }
    return res;
  }
};

int main() {
  auto solution = Solution();
  string s = "2147483648";
  int res = solution.StrToInt(s);
  cout << res << endl;
  return 0;
}