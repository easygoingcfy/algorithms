#include <iostream>
using namespace std;

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
  int size, value;
  cin >> size >> value;
  auto head = new ListNode(value);
  int start, end;
  for (int i = 0; i < size - 1; ++i) {
    cin >> end >> start;
    ListNode* cur = head;
    while (cur) {
      if (cur->val == start) {
        auto node = new ListNode(end);
        node->next = cur->next;
        cur->next = node;
      }
      cur = cur->next;
    }
  }
  int target;
  cin >> target;
  if (head->val == target) {
    head = head->next;
  } else {
    auto cur = head;
    while (cur->next) {
        if (cur->next->val == target) {
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }
  }
  for(auto cur = head; cur != nullptr; cur = cur->next) {
    cout << cur->val << " ";
  }
  cout << endl;
  return 0;
}