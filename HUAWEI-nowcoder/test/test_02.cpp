#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto res = vector<int>(501, 0);
    int N;
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        res[num] = 1;
    }
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == 1) {
            cout << res[i] << endl;
        }
    }
    return 0;
}