//字符串加解密
//可以直接用字典做，一步到位。
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void JiaMi(char& c) {
  if (isalpha(c)) {
    if (c == 'z') {
      c = 'A';
      return;
    } else if (c == 'Z') {
      c = 'a';
      return;
    }
    if (isupper(c)) {
      c = c + 'b' - 'A';
    } else {
      c = c + 'B' - 'a';
    }
  } else if (isalnum(c)) {
    if (c == '9') {
      c = '0';
    } else {
      c = c + '1' - '0';
    }
  }
}

void JieMi(char& c) {
  if (isalpha(c)) {
    if (c == 'a') {
      c = 'Z';
      return;
    } else if (c == 'A') {
      c = 'z';
      return;
    }
    if (isupper(c)) {
      c = c + 'a' - 'B';
    } else {
      c = c + 'A' - 'b';
    }
  } else if (isalnum(c)) {
    if (c == '0') {
      c = '9';
    } else {
      c = c + '0' - '1';
    }
  }
}

int main() {
  string input;
  cin >> input;
  for (auto& c : input) {
    JiaMi(c);
  }
  cout << input << endl;
  cin >> input;
  for (auto& c : input) {
    JieMi(c);
  }
  cout << input << endl;
}