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
class Solution {
  ListNode* middleNode(ListNode *head) {
    ListNode *low = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      low = low->next;
      fast = fast->next->next;
    }
    return low;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  void merge(ListNode *head, ListNode *head2) {
    ListNode *node1 = head;
    ListNode *node2 = head2;
    while (node1 && node2) {
      ListNode *node1_next = node1->next;
      ListNode *node2_next = node2->next;
      node1->next = node2;
      node2->next = node1_next;
      node1 = node1_next;
      node2 = node2_next;
    }
  }

public:
  void reorderList(ListNode *head) {
    if (head == nullptr) {
      return;
    }
    ListNode *middle_node = middleNode(head);
    ListNode *head2 = reverseList(middle_node->next);
    middle_node->next = nullptr;
    merge(head, head2);
  }
};
