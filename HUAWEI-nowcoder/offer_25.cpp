//合并两个排序的链表

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto head = new ListNode(0);
        head = dummy;
        auto top = l1, down = l2;
        while (top && down) {
            if (top->val > down->val) {
                head->next = down;
                head = head->next;
                down = down->next;
            } else {
                head->next = top;
                head = head->next;
                top = top->next;
            }
        }
        while (top) {
            head->next = top;
            head = head->next;
            top = top->next;
        }
        while (down) {
            head->next = down;
            head = head->next;
            down = down->next;
        }
    return dummy->next;
    }
};