//只能说很巧妙， 碾压了我的智商, 我用归并写的，内存还超了
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> res(501);
  int n, value;
  cin >> n;
  while (n--) {
    cin >> value;
    res[value] = 1;
  }
  for (int i = 0; i <= 500; ++i) {
    if (res[i] == 1) cout << i << endl;
  }
}
// 64 位输出请用 printf("%lld")