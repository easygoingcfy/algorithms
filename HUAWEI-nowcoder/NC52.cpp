#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        map<char, char> brackets = {
          {'(', ')'},
          {'[', ']'},
          {'{', '}'},
        };
        for (auto c: s) {
            if (brackets.find(c) != brackets.end()) {
              st.push(c);
            } else {
                if (st.size() == 0) return false;
                char top = st.top();
                if (c != brackets[top]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.size() == 0;
    }
};

int main() {
    auto s = Solution();
    string str = "()";
    bool res = s.isValid(str);
    cout << res << endl;
    return 0;
}