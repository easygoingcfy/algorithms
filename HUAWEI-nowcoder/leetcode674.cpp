//最长连续递增序列
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int left = 0, right = 0;
    while (right < n) {
        if (nums[right] > nums[right]) {
            right++;
            res = max(res, right - left + 1);
        } else {
            left = right + 1;
            right = right + 1;
        }
    }
    return res;
  }
};