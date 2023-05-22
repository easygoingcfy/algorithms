#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int len;
    cin >> input >> len;
    cout << input.substr(0, len) << endl;
}
// 64 位输出请用 printf("%lld")