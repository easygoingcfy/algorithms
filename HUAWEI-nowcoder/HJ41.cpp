//称砝码
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> weight(n), nums(n);
    int total = 0;
    for (int i = 0; i < n; ++i) cin >> weight[i];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i) total += nums[i];
    set<int> res;
    res.insert(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < nums[i]; ++j) {
            set<int> tmp(res);
            for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
                res.insert(*iter + weight[i]);
            }
        }
    }
    cout << res.size() << endl;
    return 0;
}