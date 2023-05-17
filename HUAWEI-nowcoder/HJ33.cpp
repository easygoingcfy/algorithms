#include <iostream>
#include <string>
using namespace std;

int main() {
  long long int a, b, c, d;
  while (scanf("%lld.%lld.%lld.%lld", &a, &b, &c, &d) != EOF) {
    cout << (a << 24) + (b << 16) + (c << 8) + d << endl;
    long long int num;
    cin >> num;
    a = num >> 24;
    num -= (a << 24);
    b = num >> 16;
    num -= (b << 16);
    c = num >> 8;
    num -= (c << 8);
    d = num;
    cout << a << '.' << b << '.' << c << '.' << d << endl;
  }
  return 0;
}