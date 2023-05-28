#include <iostream>
#include <string>
#include <map>
using namespace std;

int Transform(string s) {
    s = s.substr(2, s.length() - 2);
    int res = 0;
    map<char, int> alpha = {
        {'A', 10}, {'B', 11}, {'C', 12},
        {'D', 13}, {'E', 14}, {'F', 15},
    };
    for (auto c: s) {
        if (isalpha(c)) {
            res = alpha[c] + res * 16;
        } else {
            res = c - '0' + res * 16;
        }
    }
    return res;
}


int main() {
    string input;
    cin >> input;
    int res = Transform(input);
    cout << res << endl;
}