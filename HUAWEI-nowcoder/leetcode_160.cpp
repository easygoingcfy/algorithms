//相交链表
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
      set<ListNode*> array_list;
      while (top) {
        array_list.insert(top);
        top = top->next;
      }
      while (down) {
        if (array_list.find(down) != array_list.end()) {
            return down;
        }
        down = down->next;
      }
      return nullptr;
    }
};