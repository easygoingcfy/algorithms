#include <math.h>

#include <iostream>
#include <vector>

using namespace std;
#define EPS 1e-6

bool EqualZero(double d) { return fabs(d) < EPS; }

bool calculate(vector<double> array) {
  int n = array.size();
  if (n == 1) {
    return EqualZero(array[0]);
  }
  double res;
  bool success = false;
  vector<double> remaining(n - 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int m = 0;
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j) {
          remaining[m++] = array[k];
        }
      }
      remaining[m] = array[i] + array[j];
      if (calculate(remaining)) return true;
      remaining[m] = array[i] - array[j];
      if (calculate(remaining)) return true;
      remaining[m] = array[j] - array[i];
      if (calculate(remaining)) return true;
      remaining[m] = array[i] * array[j];
      if (calculate(remaining)) return true;
      if (!EqualZero(array[j])) {
        remaining[m] = array[i] / array[j];
        if (calculate(remaining)) return true;
      }
      if (!EqualZero(array[i])) {
        remaining[m] = array[j] / array[i];
        if (calculate(remaining)) return true;
      }
    }
  }
  return false;
}

int main() {
  vector<double> array(4);
  while (true) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
      cin >> array[i];
      if (EqualZero(array[i])) count++;
    }
    if (count == 4) break;
    if (calculate(array)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}