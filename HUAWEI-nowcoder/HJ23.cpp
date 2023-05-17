#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string input;
  cin >> input;
  unordered_map<char, int> umap;
  for (auto c: input) {
    umap[c]++;
  }
  int min_count = input.length();
  for (auto x: umap) {
    min_count = min(min_count, x.second);
  }
  
  for (auto c: input) {
    if (umap[c] == min_count) continue;
    cout << c;
  }
  cout << endl;
  return 0;
}

