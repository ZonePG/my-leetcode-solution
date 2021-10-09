#include <cstdio>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    int length = 0;
    ListNode *node = head;
    while (node) {
      length++;
      node = node->next;
    }
    ListNode *dummyHead = new ListNode(0, head);
    for (int subLength = 1; subLength < length; subLength <<= 1) {
      ListNode *pre = dummyHead;
      ListNode *cur = dummyHead->next;
      while (cur) {
        ListNode *head1 = cur;
        for (int i = 1; i < subLength && cur->next != nullptr; i++) {
          cur = cur->next;
        }
        ListNode *head2= cur->next;
        cur->next = nullptr;
        cur = head2;
        for (int i = 1; i < subLength && cur != nullptr && cur->next != nullptr; i++) {
          cur = cur->next;
        }
        ListNode *next = nullptr;
        if (cur != nullptr) {
          next = cur->next;
          cur->next = nullptr;
        }
        ListNode *merged = merge(head1, head2);
        pre->next = merged;
        while (pre->next) {
          pre = pre->next;
        }
        cur = next;
      }
    }
    return dummyHead->next;
  }

  ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *temp = dummyHead;
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    while (temp1 && temp2) {
      if (temp1->val <= temp2->val) {
        temp->next = temp1;
        temp1 = temp1->next;
      } else {
        temp->next = temp2;
        temp2 = temp2->next;
      }
      temp = temp->next;
    }
    if (temp1) {
      temp->next = temp1;
    } else if (temp2) {
      temp->next = temp2;
    }
    return dummyHead->next;
  }
};

int main() {
  Solution solution;
  ListNode *node4 = new ListNode(3, nullptr);
  ListNode *node3 = new ListNode(1, node4);
  ListNode *node2 = new ListNode(2, node3);
  ListNode *node1 = new ListNode(4, node2);
  solution.sortList(node1);
}
