#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void NQueen(int k, int max, vector<int>& pos);

int main() {
    int n;
    cin >> n;
    vector<int> position(100);
    NQueen(0, n, position);
}

void NQueen(int k, int max, vector<int>& pos) {
    //摆放第k行的皇后
    if (k == max) {
        for (int i = 0; i < max; ++i) {
            cout << pos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < max; ++i) {
        //遍历所有位置，看看能不能摆放成功
        int j;
        for (int j = 0; j < k; ++j) {
            if (i == pos[j] || ::abs(pos[j] - i) == k - j) {
                break;
            }
        }
        if (j == i) {
            pos[k] = i;
            NQueen(k + 1, max, pos);
        }
    }
    return;
}