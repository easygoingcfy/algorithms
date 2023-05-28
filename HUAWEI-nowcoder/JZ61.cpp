#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    set<int> dup;
    int min_value = 20, max_value = 0;
    for (int num: nums) {
        if (dup.find(num) != dup.end()) return false;
        if (num == 0) {
            continue;
        }
        dup.insert(num);
        min_value = min_value < num ? min_value : num;
        max_value = max_value < num ? num : max_value;
    }
    return max_value - min_value <= 4;
  }
};