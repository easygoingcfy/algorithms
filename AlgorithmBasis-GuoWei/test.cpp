#include <iostream>
#include <string>

using namespace std;

int main() {
    string s[2] = {"hello world", "2"};
    string s1 = "string";
    if (s1.find('c') == s1.npos) {
        cout << "not find" << endl;
    }
    return 0;
}