#include <iostream>
#include <string>
#include <utility>
using namespace std;

bool IsNumber(string s) {
  for (auto c : s) {
    if (!isdigit(c)) return false;
  }
  return true;
}

int main() {
  string input;
  pair<int, int> loc(0, 0);
  while (getline(cin, input, ';')) {
    if (input.empty()) continue;
    string sub = input.substr(1);
    if (!IsNumber(sub)) continue;
    switch (input[0]) {
      case 'A':
        loc.first -= stoi(sub);
        break;
      case 'D':
        loc.first += stoi(sub);
        break;
      case 'W':
        loc.second += stoi(sub);
        break;
      case 'S':
        loc.second -= stoi(sub);
        break;
      default:
        break;
    }
  }
  cout << loc.first << ',' << loc.second << endl;
  return 0;
}
// 64 位输出请用 printf("%lld")