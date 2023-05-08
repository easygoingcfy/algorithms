#include <iostream>
#include <string>
/*
 */

bool IsFake(char c, bool is_light);
std::string left[3], right[3], res[3];

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    for (int i = 0; i < 3; ++i) {
      std::cin >> left[i] >> right[i] >> res[i];
    }
  }
  for (char c = 'A'; c != 'L'; c++) {
    std::cout << c << std::endl;
    if (IsFake(c, true)) {
      std::cout << c << " is fake and is light than others" << std::endl;
    } else if (IsFake(c, false)) {
      std::cout << c << " is fake and is heavy than others" << std::endl;
    }
  }
  return 0;
}

bool IsFake(char c, bool is_light) {
  std::string left_str, right_str;
  for (int i = 0; i < 3; ++i) {
    if (is_light) {
      left_str = left[i];
      right_str = right[i];
    } else {
      left_str = right[i];
      right_str = left[i];
    }
    switch (res[i][0]) {
    case 'u':
      if (right_str.find(c) == right_str.npos) {
        return false;
      }
    case 'e':
      if (right_str.find(c) != right_str.npos ||
          left_str.find(c) != left_str.npos) {
        return false;
      }
    case 'd':
      if (left_str.find(c) == left_str.npos) {
        return false;
      }
    }
  }
  return true;
}