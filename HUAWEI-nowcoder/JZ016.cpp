//剑指 Offer II 016. 不含重复字符的最长子字符串
//经典的滑动窗口题目
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int max_length = 0;
    while (right < s.length()) {
      char cur = s[right];
      window[cur]++;
      right++;
      //判断是否需要左移
      while (window[cur] > 1) {
        window[s[left]]--;
        left++;
      }
      max_length = max(max_length, right - left);
    }
    return max_length;
  }
};

int main() {
  string s = "tmmzuxt";
  auto solution = Solution();
  int length = solution.lengthOfLongestSubstring(s);
  cout << length << endl;
  return 0;
}