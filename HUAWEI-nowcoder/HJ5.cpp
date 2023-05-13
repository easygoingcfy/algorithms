#include <iostream>

using namespace std;

int main() {
  string input_num;
  cin >> input_num;
  int length = input_num.length();
  int res = 0;
  for (int i = 2; i < length; ++i) {
    if (input_num[i] >= '0' && input_num[i] <= '9') {
      res = (input_num[i] - '0') + res * 16;
    } else {
      res = (input_num[i] - 'A' + 10) + res * 16;
    }
  }
  cout << res << endl;
  return 0;
}