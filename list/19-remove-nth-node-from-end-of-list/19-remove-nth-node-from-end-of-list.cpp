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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummpyNode = new ListNode(0);
    ListNode *pre = dummpyNode;
    pre->next = head;

    ListNode *low = head;
    ListNode *fast = head;
    while (n && fast) {
      n--;
      fast = fast->next;
    }

    if (n != 0) {
      return nullptr;
    }

    while (fast) {
      low = low->next;
      fast = fast->next;
      pre = pre->next;
    }

    ListNode *low_next = low->next;  
    pre->next = low_next;
    delete low;

    return dummpyNode->next;
  }
};
