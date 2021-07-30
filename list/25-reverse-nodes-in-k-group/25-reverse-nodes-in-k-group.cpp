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
public:
  ListNode* reverseList(ListNode *head, ListNode *tail) {
    ListNode *prev = nullptr;
    ListNode *tailNext = tail->next;
    ListNode *curr = head;
    while (curr != tailNext) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head->next = tailNext;
    return prev;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *prehead = dummyNode;

    while (head) {
      ListNode *tail = prehead;
      for (int i = 0; i < k; i++) {
        tail = tail->next;
        if (tail == nullptr)
          return dummyNode->next;
      }
      head = reverseList(head, tail);
      tail = prehead->next;
      prehead->next = head;
      prehead = tail;
      head = prehead->next;
    }
    return dummyNode->next;
  }
};
