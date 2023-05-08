/*
熄灯问题
*/
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

char ori_lights[5];
char lights[5];
char res[5];

int GetBit(char c, int i) { return (c >> i) & 1; }

void SetBit(char &c, int i, int v) {
  if (v) {
    c |= (1 << i);
  } else {
    c &= ~(1 << i);
  }
}

void FlipBit(char &c, int i) {
  //翻转位
  c ^= (1 << i);
}

void OutPutResult(int t, char result[]) {
  cout << "PUZZLE #" << t << endl;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      cout << GetBit(result[i], j);
      if (j < 5) {
        cout << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 6; ++k) {
        int s;
        cin >> s;
        SetBit(ori_lights[j], k, s);
      }
    }
    for (int n = 0; n < 64; ++n) {
      int switchs = n;
      memcpy(lights, ori_lights, sizeof(ori_lights));
      for (int i = 0; i < 5; ++i) {
        res[i] = switchs;
        for (int j = 0; j < 6; ++j) {
          if (GetBit(switchs, j)) {
            if (j > 0) {
              FlipBit(lights[i], j - 1);
            }
            FlipBit(lights[i], j);
            if (j < 5) {
              FlipBit(lights[i], j + 1);
            }
          }
        }
        if (i < 4) {
          lights[i + 1] ^= switchs;
        }
        switchs = lights[i];
      }
      if (lights[4] == 0) {
        OutPutResult(t, res);
        break;
      } 
    }
  }
}