#include <iostream>

using namespace std;

int exp_value();
int term_value();
int factor_value();

int main() {
  cout << exp_value() << endl;
  return 0;
}

int exp_value() {
  int result = term_value();
  bool more = true;
  while (more) {
    char op = cin.peek();
    if (op == '+' || op == '-') {
      cin.get();
      int answer = term_value();
      if (op == '+') {
        result += answer;
      } else {
        result -= answer;
      }
    } else {
      return result;
    }
  }
}

int term_value() {
  int result = factor_value();
  bool more = true;
  while (more) {
    char op = cin.peek();
    if (op == '*' || op == '/') {
      cin.get();
      int answer = factor_value();
      if (op == '*') {
        result *= answer;
      } else {
        result /= answer;
      }
    } else {
      return result;
    }
  }
}

int factor_value() {
  int result = 0;
  char c = cin.peek();
  if (c == '(') {
    cin.get();
    result = exp_value();
    cin.get();
  } else {
    while (isdigit(c)) {
      result = 10 * result + c - '0';
      cin.get();
      c = cin.peek();
    }
  }
  return result;
}