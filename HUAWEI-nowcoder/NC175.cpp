//合法的括号字符串
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param s string字符串
   * @return bool布尔型
   */
  bool isValidString(string s) {
    // write code here
    stack<char> left, star;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        left.push(i);
      } else if (s[i] == '*') {
        star.push(i);
      } else {
        if (!left.empty()) {
          left.pop();
        } else if (!star.empty()) {
          star.pop();
        } else {
          return false;
        }
      }
    }
    while (!left.empty() && !star.empty()) {
      int left_top = left.top();
      int star_top = star.top();
      if (left_top > star_top) return false;
      left.pop();
      star.pop();
    }
    return left.empty();
  }
};