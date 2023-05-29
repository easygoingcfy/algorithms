//最长回文子串
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int MaxLength(string A, int start, int end) {
        while (start >= 0 && end < A.size() && A[start] == A[end]) {
            start--;
            end++;
        }
        return end - start - 1;
    }

    int getLongestPalindrome(string A) {
        // write code here
        int res = 0;
        int odd = 0, even = 0;
        for (int i = 0; i < A.size(); ++i) {
            odd = MaxLength(A, i, i);
            if (i + 1 < A.size()) {
                even = MaxLength(A, i, i + 1);
            }
            res = max(res, max(odd, even));
        }
        return res;
    }
};