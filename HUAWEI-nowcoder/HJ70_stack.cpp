#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int matrix_count(pair<int, int> a, pair<int, int> b) {
  return (a.second * b.first) * (a.first * b.second);
}

int main() {
  int n;
  vector<pair<int, int>> array;
  stack<pair<int, int>> st;
  int res = 0;
  string input_str;
  cin >> n;
  while (n--) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    array.emplace_back(p);
  }
  cin >> input_str;
  int len = input_str.size();
  for (int i = 0; i < len; ++i) {
    if (input_str[i] == ')') {
      auto y = st.top();
      st.pop();
      auto x = st.top();
      st.pop();
      res += x.first * x.second * y.second;
      st.push(pair<int, int>(x.first, y.second));
    } else if (isalpha(input_str[i])) {
      st.push(array[input_str[i] - 'A']);
    }
  }
  cout << res << endl;
  return 0;
}