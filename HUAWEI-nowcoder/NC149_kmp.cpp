//kmp算法
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * 计算模板串S在文本串T中出现了多少次
   * @param S string字符串 模板串
   * @param T string字符串 文本串
   * @return int整型
   */
  vector<int> build_next(string S) {
    vector<int> next(S.length(), 0);
    int i = 1;
    int prefix_len = 0;
    while (i < S.size()) {
      if (S[prefix_len] == S[i]) {
        prefix_len += 1;
        next[i] = prefix_len;
        i++;
      } else {
        if (prefix_len == 0) {
          next[i] = 0;
          i++;
        } else {
          prefix_len = next[prefix_len - 1];
        }
      }
    }
    return next;
  }

  int kmp(string S, string T) {
    // write code here
    if (S.length() > T.length()) return 0;
    vector<int> next = build_next(S);
    int res = 0;
    int i = 0, j = 0;
    while (i < T.size()) {
      if (T[i] == S[j]) {
        i++, j++;
      } else if(j > 0) {
        j = next[j - 1];
      } else {
        i++;
      }
      if (j == S.length()) res++;
    }
    return res;
  }
};