#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string input;
    unordered_map<char, int> umap;
    cin >> input;
    for (auto c: input) {
        umap.emplace(c, 1);
    }
    cout << umap.size() << endl;
}
// 64 位输出请用 printf("%lld")