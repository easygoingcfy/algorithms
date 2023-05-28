//相交链表，双指针解法
#include <iostream>
#include <vector>
#include <set>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      auto top = headA, down = headB;  
      while (top != down) {
        if (top) {
            top = top->next;
        } else {
            top = headB;
        }
        if (down) {
            down = down->next;
        } else {
            down = headA;
        }
      }
      return top;
    }
};