//汽水瓶

#include <iostream>
#include <vector>
using namespace std;

int MaxWater(int n) {
  int res = 0;
  while (n >= 3) {
    res += n / 3;
    n = n / 3 + n % 3;
  }
  if (n == 2) res++;
  return res;
}

int main() {
  int n;
  cin >> n;
  while (n != 0) {
    int res = MaxWater(n);
    cout << res << endl;
    cin >> n;
  }
}