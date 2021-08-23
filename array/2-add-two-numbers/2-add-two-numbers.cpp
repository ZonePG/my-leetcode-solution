/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = l1;
    int cr = 0;
    ListNode *pre;
    while (l1 && l2) {
      int sum_single = l1->val + l2->val + cr;
      cr = sum_single / 10;
      int update_num = sum_single % 10;
      l1->val = update_num;
      pre = l1;
      l1 = l1->next;
      l2 = l2->next;
    }

    if (l2) {
      pre->next = l2;
      l1 = l2;
    }

    while (l1) {
      int sum_single = l1->val + cr;
      cr = sum_single / 10;
      int update_num = sum_single % 10;
      l1->val = update_num;
      pre = l1;
      l1 = l1->next;
    }

    if (cr) {
      ListNode *new_tail = new ListNode(1, nullptr);
      pre->next = new_tail;
    }

    return head;
  }
};

int main() {}
