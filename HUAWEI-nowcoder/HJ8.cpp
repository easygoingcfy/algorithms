#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, key, value;
    map<int, int> umap;
    cin >> n;
    while (n--) {
        cin >> key >> value;
        if (umap.find(key) == umap.end()) {
            umap[key] = value;
        } else {
            umap[key] += value;
        }
    }
    for (auto iter = umap.begin(); iter != umap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}