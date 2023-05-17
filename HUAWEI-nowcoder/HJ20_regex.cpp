#include <iostream>
#include <regex>
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

    string my_regex[4] = {"[a-z]", "[A-Z]", "\\d", "[^a-zA-Z0-9]"};
    int type = 0;
    for (auto s : my_regex) {
      regex pattern(s);
      if (regex_search(input, pattern)) type++;
    }
    if (type < 3) {
      output(false);
      continue;
    }

    regex sub_pattern(".*(...).*\\1.*");
    if (regex_search(input, sub_pattern)) {
      output(false);
    } else {
      output(true);
    }
  }
  return 0;
}