//括号的最大嵌套深度  由于只用考虑栈的大小， 可以简化
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  int maxDepth(string s) {
    int res = 0;
    int depth = 0;
    if (s.length() == 0) return 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '(' && s[i] != ')') {
        continue;
      }
      if (s[i] == '(') {
        st.push(s[i]);
      } else {
        depth = st.size();
        res = max(res, depth);
        st.pop();
      }
    }
    return res;
  }
};

int main() {
    auto s = Solution();
    string str = "(1+(2*3)+((8)/4))+1";
    int res = s.maxDepth(str);
    cout << res << endl;   
    return 0;
}