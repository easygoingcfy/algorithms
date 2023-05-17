#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void output(bool ok) {
  if (ok) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }
}

int main() {
  string input;
  while (getline(cin, input)) {
    if (input.length() <= 8) {
      output(false);
      continue;
    }
    vector<int> type(5, 0);
    for (auto c : input) {
      if (islower(c))
        type[0] = 1;
      else if (isupper(c))
        type[1] = 1;
      else if (isdigit(c))
        type[2] = 1;
      else
        type[3] = 1;
    }

    if (type[0] + type[1] + type[2] + type[3] < 3) {
      output(false);
      continue;
    }

    set<string> dup;
    bool duplicate = false;
    for (int i = 0; i < input.length() - 2; ++i) {
      string sub = input.substr(i, 3);
      if (dup.find(sub) != dup.end()) {
        duplicate = true;
        break;
      }
      dup.emplace(sub);
    }
    if (duplicate) {
      output(false);
    } else {
      output(true);
    }
  }
}
// 64 位输出请用 printf("%lld")