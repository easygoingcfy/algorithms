//特殊密码锁

//描述
//有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。
//
//然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
//
//当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
//
//输入
//两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
//输出
//至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。

#include <iostream>
#include <string>

using namespace std;

void FlipBit(int& a, int index) {
  a ^= (1 << index);
}

void SetBit(int& a, int index, char c) {
  if (c == '1') {
    a |= (1 << index);
  } else {
    a &= ~(1 << index);
  }
}

bool GetBit(int a, int index) {
    return (a >> index) & 1;
}

void Output(int result) {
    if (result >= 0) {
        cout << result;
    } else {
        cout << "impossible";
    }

}

int main() {
  string input_str, output_str;
  cin >> input_str;
  cin >> output_str;
  int length = input_str.length();
  int original=0, target=0,
      cur=0; // n < 30可以用Int保存密码锁的状态，每一位对应一个按钮的状态

  for (int i = 0; i < input_str.length(); ++i) {
    SetBit(original, i, input_str[i]);
    SetBit(target, i, output_str[i]);
  }

  int min_count = 30;
  for (int n = 0; n < 2; ++n) {
    cur = original;
    int count = 0;
    if (n == 0) {
        count++;
        //按下第一个按钮
        FlipBit(cur, 0);
        if (length > 1) {
            FlipBit(cur, 1);
        }
    }
    for (int i = 1; i < length; ++i) {
        if (GetBit(cur, i - 1) != GetBit(target, i - 1)) {
            count++; //按下第i个按钮
            FlipBit(cur, i - 1);
            FlipBit(cur, i);
            if (i + 1 < length) {
                FlipBit(cur, i + 1);
            }
        }
        if (cur == target) {
            min_count = min(count, min_count);
            break;
        }
    }
  }
  if (min_count < 30) {
    cout << min_count;
  } else {
    cout << "impossible";
  }

  return 0;
}