//计算质数
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> erato(int n) {
      //埃式筛法
      if (n < 2) {
        return vector<int>();
      }
      vector<int> res(n, 1);
      res[0] = 0;
      res[1] = 0;
      int p = 2;
      while (p * p < n) {
        for (int i = p * p; i < n; i += p) {
            res[i] = 0;
        }
        while(res[++p] == 0); //遍历到下一个质数
      }
      return res;
    }
    int countPrimes(int n) {
        int count = 0;
        vector<int> res = erato(n);
        for (int i = 0; i < res.size(); ++i) {
            if (res[i]) count++;
        }
        return count;

    }
};

int main() {
    int n = 10;
    auto so = Solution();
    int res = so.countPrimes(10);
    cout << res << endl;
    return 0;
}