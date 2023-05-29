//火锅问题 这个应该是贪心算法
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> food(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        food[i] = true;
    }
    sort(food.begin(), food.end());
    int start = food[0];
    int end = food[food.size() - 1];
    int res = INT_MIN;
    for (int i = food.size() - 1; i >= 0; --i) {
        int cur = 0;
        int cur_time = food[i];
        for (int j = i; j >= 0; j--) {
            if (cur_time >= food[j]) {
                cur++;
                cur_time -= n;
            }
        }
        res = max(cur, res);
    }
    cout << res << endl;
}